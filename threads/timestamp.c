#include<pthread.h>
#include<stdio.h>
#include<stdint.h>
#include "time.h"
void *task_body(void* pv)
{
 int i=0;
 time_t secn;
 struct tm* current_time;
 secn = time(NULL);
 current_time = localtime(&secn);
 printf("%02d : %02d : %02d \n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
 }
 int main()
 {
 int i, n=10;
 pthread_t ptrarray[n];
 for(i=0; i<n; ++i)
 {
 pthread_create(&ptrarray[i], NULL, task_body, (void *)(__intptr_secn)i);
 sleep(3);
 }
 for(i=0; i<n; i++) 
 {
 pthread_join(ptrarray[i], NULL);
 }
 return 0;
 }
