#include<unistd.h>
	#include <string.h>
	#include<stdio.h>
	#include<stdlib.h>
	#include <sys/wait.h>
	#include <string.h>
	
	
	
	int main()
	{
		int ret1,reti;
		int chld_1=fork();
		int chld_2,chld_3,chld_4,chld_5;
		char *s;
		char *ss;
		ss="./s.out";
		s="s.out"; 
		if(chld_1<0||chld_2<0||chld_3<0)
		{
		perror("fork");
		exit(1);
		}
		if(chld_1==0)
		{ 
		execlp("gcc","gcc","-c","mul.c",NULL);
		printf("Compilation of mul.c is done\n");
	    	}
	    	else
	    	{
	    	waitpid(chld_1, &reti, 0);
	    
	    	}
	
		chld_2=fork();
		if(chld_2==0)
		{
	    	execlp("gcc","gcc","-c","add.c",NULL);
		printf("Compilation of add.c is done\n");
		}
	    	else
	    	{
		waitpid(chld_2, &reti, 0);
	    	}
		chld_3=fork();
		if(chld_3==0)
		{
	    	execlp("gcc","gcc","-c","test.c",NULL);
		printf("Compilation of test.c is done\n");
		}
	    	else
	    	{
		waitpid(chld_3, &reti, 0);
	    	}
		chld_4=fork();
		if(chld_4==0)
		{
	  	execlp("gcc","gcc","mul.o","add.o","test.o","-o","s.out",NULL);
		printf("Linking is done\n");
		printf("Execution:\n");
		}
	    	else
	    	{
		waitpid(chld_4, &reti, 0);
		  } 
		execl("./s.out", "./s.out", NULL); 	 
		exit(0);
	}
