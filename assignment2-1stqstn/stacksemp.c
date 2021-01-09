#include "stacksemp.h"

#define max_items 7

#define size_of_buffer 7

sem_t empty;
sem_t full;
int buffer_in = 0;
int buffer_out = 0;
int item = 0;
int buffer[size_of_buffer];

void *producer(void *pno) {
  if (buffer_in == size_of_buffer - 1) {
    printf("stack of Producer is full \n");
  } 
  else {
    for (int i = 0; i < max_items; i++) {
      item = rand();
      sem_wait(&empty);
      
      buffer[buffer_in] = item;
      printf("Producer %d: insert Item %d at %d\n", *((int *)pno), buffer[buffer_in],
             buffer_in);
      buffer_in = (buffer_in + 1) % size_of_buffer;
      sem_post(&full);
    }
  }
}

void *consumer(void *cno) {
  if (buffer_out == size_of_buffer - 1) {
    printf("Stack of consumer is full\n");
  } 
  else {
    int item = 0;
    for (int i = 0; i < max_items; i++) {
      sem_wait(&full);
      
      item = buffer[buffer_out];
      printf("Consumer %d: Remove the Item %d from %d\n", *((int *)cno), item, buffer_out);
      buffer_out = (buffer_out + 1) % size_of_buffer;
      sem_post(&empty);
    }
  }
}

void main() {
  pthread_t pro[7], con[7];
  sem_init(&empty, 0, size_of_buffer);
  sem_init(&full, 0, 0);
//array initialisation
  int a[7] = {1, 2, 3, 4, 5,6,7}; 
//creating threads
  for (int i = 0; i < 7; i++) {
    pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
  }
  for (int i = 0; i < 7; i++) {
    pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
  }
//joining threads
  for (int i = 0; i < 7; i++) {
    pthread_join(pro[i], NULL);
  }
  for (int i = 0; i < 7; i++) {
    pthread_join(con[i], NULL);
  }
//destroying threads
  sem_destroy(&empty);
  sem_destroy(&full);
}
