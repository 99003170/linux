#ifndef __SIGNALSENDING_H
#define __SIGNALSENDINGL_H

#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void child_process();
void sighup(); 
void sigint(); 
void sigquit(); 

#endif
