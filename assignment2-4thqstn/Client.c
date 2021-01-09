#include "ServerClient.h"

int main()
{
	int ret, nbytes;
	mqd_t message_query_id;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	
	message_query_id=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(message_query_id<0)
	{
		printf("error opening");
		exit(1);
	}

	char str[20] = "shashank";
	
	ret=mq_send(message_query_id,str,20,5);
	if(ret<0)
	{
		printf("error sending");
		exit(2);
	}

	char buffer[8192];
	int maxlen=256,prio;
	nbytes=mq_receive(message_query_id,buffer,maxlen,&prio);
	if(nbytes<0)
	{
		printf("error receiving");
		exit(2);
	}
	buffer[nbytes]='\0';
	printf("msg from server : %s\n",buffer);
	
	mq_close(message_query_id);

	return 0;
}
