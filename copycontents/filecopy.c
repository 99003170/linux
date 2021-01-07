#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int first,second,nbytes, flag;
	first=open("a.txt",O_RDONLY);
	second=open("b.txt",O_WRONLY|O_CREAT, 0666);
	if(first<0 || second<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(first,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	flag = write(second,buf,nbytes);
	close(first);
	close(second);
	if(flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
