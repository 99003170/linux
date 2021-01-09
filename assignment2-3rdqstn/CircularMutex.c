#include "CircularMutex.h"

#define max_items 7 
#define buffer_size 7 

int input = 0;
int output = 0;
int buffer[buffer_size];
pthread_mutex_t mutex;

void *producer(void *pd)
{   
    int item;
    for(int i = 0; i < max_items; i++) {
        item = rand(); 
        pthread_mutex_lock(&mutex);
        
        while (((input + 1) % buffer_size) == output)
        {
        
           buffer[input] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pd),buffer[input],input);
           input = (input + 1) % buffer_size;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cd)
{   
    int item=0;
    for(int i = 0; i < max_items; i++) {
        pthread_mutex_lock(&mutex);
        /* wait for buffer to fill */
        while (input == output) 
        {
        
           item = buffer[output];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cd),item, output); 
           output = (output + 1) % buffer_size;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t pd[7],cd[7];
    pthread_mutex_init(&mutex, NULL);

    int a[7] = {1,2,3,4,7,6,8}; 

    for(int i = 0; i < 7; i++) {
        pthread_create(&pd[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 7; i++) {
        pthread_create(&cd[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 7; i++) {
        pthread_join(pd[i], NULL);
    }
    for(int i = 0; i < 7; i++) {
        pthread_join(cd[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
