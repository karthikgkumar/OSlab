#include <stdio.h>
#include <stdlib.h>

struct process
{
    int arr_t;
    int burst_t;
    int comp_t;
    int turn_t;
    int wait_t;
};

struct process p[10];

void main(){
    int n;
    printf("Enter total number of process\n");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
       printf("Enter arrival time\n"  );
       scanf("%d",&p[i].arr_t);
       printf("Enter burst time\n"  );
       scanf("%d",&p[i].burst_t);
       
       
    }
    p[0].comp_t=p[0].burst_t;
    for (int i = 1; i < n; i++)
    {
        p[i].comp_t=p[i-1].comp_t+p[i].burst_t;
    }
    for (int j = 0; j < n; j++)
    {
        p[j].turn_t=p[j].comp_t-p[j].arr_t;
        p[j].wait_t=p[j].turn_t-p[j].burst_t;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Turnaround time %d\n", p[i].turn_t);
        printf("Waiting Time %d\n", p[i].wait_t);
        
    }
    
    
    

}
