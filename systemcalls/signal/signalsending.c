
#include "signalsending.h"

void child_process()
{ 
    int process_id; 
  
    
    if ((process_id = fork()) < 0) { 
        printf("error");
        exit(1); 
    } 
  
    if (process_id == 0) { 
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        while(1)
    } 
  
    else 
    { 
        printf("\nPARENT - SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3);
        printf("\nPARENT - SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3);
        printf("\nPARENT - SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 

void sighup()   
{ 
    signal(SIGHUP, sighup); 
    printf("CHILD - received SIGHUP\n"); 
} 

void sigint() 
  
{ 
    signal(SIGINT, sigint); 
    printf("CHILD - received SIGINT\n"); 
} 
  
void sigquit() 
{ 
    printf("child was killed\n"); 
    exit(0); 
} 
