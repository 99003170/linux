#include "shm.h"

int main()
{
	int file_size=4096; 
	int file1,offset=0;
	file1=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(file1<0)
	{
		printf("error in opening");
		exit(1);
	}
    ftruncate(file1, file_size);
	void *pbase;
	pbase=mmap(0,file_size, PROT_READ, MAP_SHARED,file1,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		exit(1);
	}
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	char buffer[64];
	sem_wait(qs);
	sem_wait(ps);
        strncpy(buffer,pbase,10);
	printf("buffer value=%s\n",buffer);
	strcpy(buffer,pbase+10);
	printf("buffer=%s\n",buffer);
	 sem_post(ps);
	sem_unlink("s1");
	sem_unlink("s2");
	munmap(pbase,file_size);
	return 0;
}

