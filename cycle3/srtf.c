//Shortest Remaining Time First

/*
It is a pre-emptive version of SJF (Shortest Job First) algorithm,
where the process with the shortest remaining burst time 
is selected for execution at each time step.
*/

// Enter the number of processes: 4
// Enter the arrival time and burst time for process 1: 0 3
// Enter the arrival time and burst time for process 2: 1 6
// Enter the arrival time and burst time for process 3: 4 4
// Enter the arrival time and burst time for process 4: 6 2

// Process Arrival Time    Burst Time      Turnaround Time Waiting Time
// 1       0               3               3               0
// 2       1               6               14              8
// 3       4               4               4               0
// 4       6               2               4               2
// Average waiting time: 2.50
// Average turnaround time: 6.25


#include <stdio.h>
#define Max 100

struct process {
    int pid;    // process ID
    int arrival_time;   // arrival time of the process
    int burst_time; // burst time of the process
    int remaining_time; // remaining time to complete the process
    int waiting_time;   // waiting time of the process
    int turnaround_time;    // turnaround time of the process
};



int main() {

    // Number of Processes
    int n; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Array to store Multiple Processes
    struct process p[Max];


    // Reading the Process Details From the User
    for (int i = 0; i < n; i++) {

        p[i].pid = i+1;
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);

        // Initilizing the Remaining Time
        p[i].remaining_time = p[i].burst_time;
    }

    // current time
    int t = 0;  
    
    // number of completed processes
    int completed = 0;  

    // loop till the execution of the last process is complete
    while (completed < n) {

        // index of the process with shortest remaining time
        int shortest = -1;  

        // Finding the process with shortest Remaining Time in the Array
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= t && p[i].remaining_time > 0) {
                if (shortest == -1 || p[i].remaining_time < p[shortest].remaining_time) {
                    shortest = i;
                }
            }
        }

        //this is executed when the Arrival Time of first process is very late.
        if (shortest == -1) {   // no process is ready yet
            t++;
            //preventing execution of the remaining codes
            continue;
        }

        // Decrementing the Remaining Time of The shortest Process
        p[shortest].remaining_time--;


        if (p[shortest].remaining_time == 0) {  // process is completed
            completed++;
            // completion time=t+1
            p[shortest].turnaround_time = t + 1 - p[shortest].arrival_time;
            p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
        }
        t++;
    }

    // print results
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,p[i].turnaround_time, p[i].waiting_time);
        
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time/n);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time/n);

    return 0;
}