#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int  main(){
    void *shared_memory;
    char buffer[100];
    int shmid;
    
 shmid = shmget((key_t)1222, 1024, 0666 |IPC_CREAT);
printf("Key of the Shared Memory is %d\n", shmid);
shared_memory= shmat(shmid, NULL, 0);
printf("Process attached at %p\n",shared_memory);
printf("Enter some data to write to shared_memory: \n");
read(0,buffer, 100);
 strcpy (shared_memory, buffer);
printf("You wrote is: %s",  (char *)shared_memory);
 return 0;
 }

// Key of the Shared Memory is 4882443
// Process attached at 0x7fe6ad332000
// Enter some data to write to shared_memory: 
// hello
// You wrote is: hello