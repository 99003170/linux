#include "ServerClient.h"

int main()
{
	int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t message_query_id;
	
	message_query_id=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(message_query_id<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buf[8192];
	int maxlen=256,prio;
	
	printf("Waiting for message \n");
	nbytes=mq_receive(message_query_id,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("msg from client : %s\n",buf);

	
	for (int i=0; buf[i]!='\0'; i++)
    {
        if (buf[i]>='A' && buf[i]<='Z')
            buf[i] = buf[i] + 'a' - 'A';
        else if (buf[i]>='a' && buf[i]<='z')
            buf[i] = buf[i] + 'A' - 'a';
    }

	
	ret = mq_send(message_query_id,buf,100,100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	/* Close the Queue */
	mq_close(message_query_id);
	return 0;
}

