#include<pthread.h>
#include<stdio.h>
#include<stdint.h>
int array[1000]={};
uint32_t final_sum=0;
void* task_body(void* pv)
{
        int i;

        int num=(intptr_t)pv;
        intptr_t temp_sum=0;
        int j=num*100;
        int k=j+100;
        for(i=j;i<k;i++)
                temp_sum +=array[i];
        pthread_exit((void *)temp_sum);
}
int main()
{
        int i,k=0,n=10;
        for(i=0;i<1000;i++)
                array[i]=i;
        pthread_t ptarr[n];
        int temp_sum[n],final_sum=0;
        for(i=0;i<n;i++)
        {
          temp_sum[i]=0;
        }
        for(i=0;i<n;i++)
        {
          pthread_create(&ptarr[i],NULL,task_body,(void*)i;
        }
        for(i=0;i<n;i++)
          pthread_join(ptarr[i],(void *)&temp_sum[i]);
        for(i=0;i<n;i++){
                final_sum += temp_sum[i];
                }
        printf("%d\n",final_sum);
        return 0;
}
