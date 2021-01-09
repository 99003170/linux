#include "pipes.h"

void main() 
{
    int file1;
    file1 = mkfifo("pipe_one",0666);
    if(file1<0)
        printf("pipe_one not created\n");
    else
        printf("pipe_one created\n");
    int file2;
    file2 = mkfifo("pipe_two",0666);
    if(file2<0)
        printf("\npipe_two not created");
    else
        printf("\npipe_two is created\n");
}
