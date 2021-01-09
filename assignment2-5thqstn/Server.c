#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
int ret;
mqd_t mqid;
struct mq_attr attrib;
attrib.mq_msgsize=256;
attrib.mq_maxmsg=10;
// Open a Message Queue in Server Process
mqid=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attrib);
if(mqid<0)
{
printf("unable to open");
exit(1);
}
char value[]="hello";
int len=strlen(value);
ret=mq_send(mqid,value,len+1,5);
if(ret<0)
{
perror("mq_send");
exit(2);
}
mq_close(mqid);
return 0;
}

