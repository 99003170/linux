#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int temp,status;
char command[10];
temp=fork();
if(temp<0)
{
printf("error");
}
else if(temp==0)
{
printf("cmd to be entered");
scanf("%s",&command);
execlp(command,command,NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("The child has comleted\n");
printf("The status is %d",WEXITSTATUS(status));
}
}

