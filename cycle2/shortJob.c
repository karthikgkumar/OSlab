#include<stdio.h> 
#include<stdlib.h> 
struct sp
{
    int pid;    
    int btime;
    int wtime;
    int ttime;
    int awtime;
}
p[10];
int main()
{
    int i,j,n;
    int towtwtime=0,totttime=0,awtime=0;
    struct sp tmp;  
    printf("\n shortest job first scheduling ..\n"); 
    printf("enter the no of process "); 
    scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
        printf("enter process id :P"); 
        scanf("%d",&p[i].pid); 
        printf("enter burst time ");
        scanf("%d",&p[i].btime); 

    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;

 
    for(i=0;i<n-1;i++){

        for(j=i+1;j<n;j++)
        {
            if(p[i].btime>p[j].btime)
            {
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        towtwtime+=p[i].wtime;



    }   

    printf("\n total waiting time :%d\n", towtwtime );
    printf("\n average waiting time :%f\n",(float)towtwtime/n); 
    printf("\n total turn around time :%d\n",totttime);
    printf("\n average turn around time: :%f\n",(float)totttime/n); 
}


//  scenario in which only one process is having very low-priority (for example 127) and we are giving other process with high-priority, this can lead indefinitely waiting for the process for CPU which is having low-priority, this leads to Starvation.

// Differences between Deadlock and Starvation in OS are as follows: 

// Deadlock occurs when none of the processes in the set is able to move ahead due to occupancy of the required resources by some other process as shown in the figure below, on the other hand, Starvation occurs when a process waits for an indefinite period of time to get the resource it requires.
// Another name for deadlock is Circular Waiting. Another name for starvation is Lived lock.
// When deadlock occurs no process can make progress, while in starvation apart from the victim process other processes can progress or proceed.

// solution to Starvation: Aging

// Aging is a technique of gradually increasing the priority of processes that wait in the system for a long time. For example, if priority range from 127(low) to 0(high), we could increase the priority of a waiting process by 1 Every 15 minutes. Eventually, even a pint