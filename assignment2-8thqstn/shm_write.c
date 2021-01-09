
#include "shm.h"

int main()
{
	int filesz=4096; 
	int fd,offset=0;
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(fd, filesz);
	void *pbase;
	pbase=mmap(0,filesz, PROT_WRITE, MAP_SHARED,fd,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		exit(1);
	}
	char buf[64];
    char str[]="SHASHANKVODELALTTSMANYATATECHPARK";
       sem_wait(ps);
	strncpy(pbase,str,20);	
	sem_post(ps);
	sem_post(qs);
	printf("buf=%s\n",str);
	munmap(pbase,filesz);
	return 0;
}
