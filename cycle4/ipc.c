#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define SEGSIZE 100
int main(int argc, char *argv[])
{
    int shmid, cntr;
    key_t key;
    char *segptr;
    char buff[] = "Data Test!!!";
    key = ftok(".", 's');
    if ((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if ((shmid = shmget(key, SEGSIZE, 0)) == -1)
        {
            perror("shmget");
            exit(1);
        }
    }
    else
    {
        printf("Creating a new shared memory seg \n");
        printf("SHMID:%d", shmid);
    }
    system("ipcs –m");
    if ((segptr = (char *)shmat(shmid, 0, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    printf("Writing data to shared memory...\n");
    strcpy(segptr, buff);
    printf("DONE\n");
    printf("Reading data from shared memory...\n");
    printf("DATA:-%s\n", segptr);
    printf("DONE\n");
    printf("Removing shared memory Segment...\n");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        printf("Can‟t Remove Shared memory Segment...\n");
    else
        printf("Removed Successfully");
}

// OUTPUT

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    

// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status      
// 0x00000000 720896     mec        600        4194304    2          dest         
// 0x00000000 3309569    mec        606        6517440    2          dest         
// 0x00000000 3112962    mec        606        11704320   2          dest         
// 0x00000000 1736707    mec        600        524288     2          dest         
// 0x00000000 393220     mec        600        524288     2          dest         
// 0x00000000 3145733    mec        606        11704320   2          dest         
// 0x00000000 3178502    mec        606        2880000    2          dest         
// 0x00000000 3211271    mec        606        2880000    2          dest         
// 0x00000000 3342344    mec        606        6517440    2          dest         
// 0x00000000 557065     mec        600        524288     2          dest         
// 0x73060059 3440650    mec        666        100        0                       

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     

// SHMID:3440650Writing data to shared memory...
// DONE
// Reading data from shared memory...
// DATA:-Data Test!!!
// DONE
// Removing shared memory Segment...