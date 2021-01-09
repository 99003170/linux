
#include "shm.h"

int main()
{
	int file_size=4096; 
	int file1,offset=0;
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	file1=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(file1<0)
	{
		printf("failed to open");
		exit(1);
	}
    ftruncate(file1, file_size);
	void *pbase;
	pbase=mmap(0,filesz, PROT_WRITE, MAP_SHARED,fd,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		exit(1);
	}
	char buffer[64];
    char str[]="SHASHANKVODELALTTSMANYATATECHPARK";
       sem_wait(ps);
	strncpy(pbase,str,20);	
	sem_post(ps);
	sem_post(qs);
	printf("buffer=%s\n",str);
	munmap(pbase,filesz);
	return 0;
}
