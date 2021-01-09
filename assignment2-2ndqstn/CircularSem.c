
#include "CircularSem.h"

#define max_items 7 
#define Size_of_buffer 7

sem_t empty;
sem_t full;
int input = 0;
int output = 0;
int buffer[Size_of_buffer];
pthread_mutex_t mutex;

void *producer(void *pd)
{   
    int item;
    for(int i = 0; i < max_items; i++) {
        item = rand(); 
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        while (((input + 1) % Size_of_buffer) == output)
        {
           buffer[input] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pd),buffer[input],input);
           input = (input + 1) % Size_of_buffer;     
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cd)
{   
    int item=0;
    for(int i = 0; i < max_items; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        /* wait for buffer to fill */
        while (input == output) 
        {
           item = buffer[output];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cd),item, output); 
           output = (output + 1) % Size_of_buffer;     
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_t pd[7],cd[7];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,Size_of_buffer);
    sem_init(&full,0,0);

    int array[7] = {1,2,3,4,5,6,7}; 

    for(int i = 0; i < 7; i++) {
        pthread_create(&pd[i], NULL, (void *)producer, (void *)&array[i]);
    }
    for(int i = 0; i < 7; i++) {
        pthread_create(&cd[i], NULL, (void *)consumer, (void *)&array[i]);
    }

    for(int i = 0; i < 7; i++) {
        pthread_join(pd[i], NULL);
    }
    for(int i = 0; i < 7; i++) {
        pthread_join(cd[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
