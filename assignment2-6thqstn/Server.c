#include "ServerClient.h"

int main()
{
	int ret,nbytes;
	struct mq_attr attrib;
	struct stat sb;
	attrib.mq_msgsize=256;
	attrib.mq_maxmsg=10;
	mqd_t mqid;
	
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attrib);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buf[20];
	int maxlen=256,prio;
	
	printf("Waiting for message from Client \n");
	nbytes=mq_receive(mqid,buf,1024,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	
	lstat(buf, &sb);
	
	ret = mq_send(mqid,(const char *)&sb,sizeof(sb),100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	
	mq_close(mqid);
	return 0;
}
