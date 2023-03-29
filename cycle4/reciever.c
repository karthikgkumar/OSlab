#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,0666);
    printf("Key of the Shared Memory is %d\n",shmid);
    shared_memory= shmat(shmid, NULL, 0);
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from shared memory is: %s\n", (char *)shared_memory);
 return 0;
}



// Key of the Shared Memory is 4882443
// Process attached at 0x7effad1e0000
// Data read from shared memory is: hello   