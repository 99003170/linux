#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int ret,nbytes;
struct mq_attr attrib;
attrib.mq_msgsize=256;
attrib.mq_maxmsg=10;
mqd_t mqid;

mqid=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attrib);
if(mqid<0)
{
printf("unable to open");
exit(1);
}
char buffer[8192];
int maxlength=256,priority;
nbytes=mq_receive(mqid,buffer,maxlength,&priority);
if(nbytes<0)
{
printf("unable to receive");
exit(2);
}
buffer[nbytes]='\0';
int k;
        printf("%s",buffer);
k=execlp("/usr/bin/echo","echo",buffer,0);
               if(k<0)
{
perror("execlp");
exit(1);
}
exit(5);

printf("receive msg:%s,nbytes=%d,prio=%d\n",buffer,nbytes,priority);
mq_close(mqid);
return 0;
}
