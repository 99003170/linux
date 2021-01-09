#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

int tot_lines, tot_characters, tot_words;
int first,n,d,i;
char ch[16384];
first=open("c.txt",O_RDONLY);
if(first<0)
{
	printf("error");
	exit(1);
}
tot_words = 0;
tot_lines = 0;
while(n=read(first,ch,sizeof(ch)))
	{
    	for(i=0;i<n;i++)
        	{
            
            	if (ch[i] == '\n')
               	tot_lines++;
            
            	if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               	tot_words++;
        	}
        tot_characters=n;
    }
    
    close(first);
int getLines()
{
  printf("%d\n",tot_lines);
}
int getCharacters()
{
  printf("%d\n",tot_characters);
}
int getWords()
{
  printf("%d\n",tot_words);
}
getLines();
getCharacters();
getWords();
return 0;
}
