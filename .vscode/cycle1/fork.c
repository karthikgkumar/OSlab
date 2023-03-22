
#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
int  main()
{
    int pid,pid1,pid2;
    int count=0;
    pid=fork();
    if(pid==-1)
    {
    printf("ERROR \n"); 
    exit(1);
    }
    if(pid==0)
    { 
    pid2=getpid();
    count+=2;
    printf(" the child process ID is %d and count =%d\n", pid2,count);}
    else
    {

    pid1=getpid();
    count+=1;
    printf("the parent process ID is %d and count = %d\n", pid1,count);
    
    } 
}
