#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int temp,status;
temp=fork();
if(temp<0)
{
printf("error");
}
else if(temp==0)
{
execlp("gcc","gcc","t.c","-o","ta",NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
//child process is created
printf("child is created\n");
printf("status is %d",WEXITSTATUS(status));
}
}
