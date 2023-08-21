#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

void non_preemptive_sjf(int n, struct Process *processes) {
    int i, j, time = 0, total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0, current = -1;
    float throughput;

    for (i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].response_time=-1;
    }

    while (1) {
        int shortest = MAX_PROCESS, index = -1;
        for (i = 0; i < n; i++) {
        // find the shortest job among available processes
            if (processes[i].arrival_time <= time && processes[i].remaining_time <= shortest && processes[i].remaining_time > 0) {
                shortest = processes[i].remaining_time; // change the shortest burst time
                index = i;  //index of shortest job
            }
        }
        // if no process is found as shortest
        if (index == -1) {
            printf("CPU idle for 1 unit\n");
            time++;
            continue;
        }
        
        printf("Process P%d starts at time %d\n", processes[index].pid, time);
        if(processes[index].response_time==-1)
            	{processes[index].response_time = time - processes[index].arrival_time;}
        //decrease burst time
        processes[index].remaining_time=0;
        //incr time
        time=time+processes[index].burst_time;
	
	//calculate 
        
            processes[index].completion_time = time;
            processes[index].waiting_time = processes[index].completion_time - processes[index].arrival_time - processes[index].burst_time;
            processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            total_waiting_time += processes[index].waiting_time;
            total_turnaround_time += processes[index].turnaround_time;
            total_response_time += processes[index].response_time;
            current = -1;
        

	//if all process is complete then break from while
        int done = 1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;
                break;
            }
        }
        if (done) break;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    printf("\nAverage waiting time: %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
    printf("Average response time: %f\n", (float)total_response_time / n);
    throughput = (float)n / time;
    printf("Throughput: %f processes per unit time\n", throughput);
}

void preemptive_sjf(int n, struct Process *processes) {
    int i, j, time = 0, total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0, current = -1;
    float throughput;

    for (i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].response_time=-1;
    }

    while (1) {
        int shortest = MAX_PROCESS, index = -1;
        for (i = 0; i < n; i++) {
        // find the shortest job among available processes
            if (processes[i].arrival_time <= time && processes[i].remaining_time <= shortest && processes[i].remaining_time > 0) {
                shortest = processes[i].remaining_time; // change the shortest burst time
                index = i;  //index of shortest job
            }
        }
        // if no process is found as shortest
        if (index == -1) {
            printf("CPU idle for 1 unit\n");
            time++;
            continue;
        }
        //if a process preempts the current process
        if (current != index) {
            printf("Process P%d starts at time %d\n", processes[index].pid, time);
            if(processes[index].response_time==-1)
            	{processes[index].response_time = time - processes[index].arrival_time;}
            current = index;
        }
        //decrease burst time
        processes[index].remaining_time--;
        //incr time
        time++;
	
	//calculate 
        if (processes[index].remaining_time == 0) {
            processes[index].completion_time = time;
            processes[index].waiting_time = processes[index].completion_time - processes[index].arrival_time - processes[index].burst_time;
            processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            total_waiting_time += processes[index].waiting_time;
            total_turnaround_time += processes[index].turnaround_time;
            total_response_time += processes[index].response_time;
            current = -1;
        }

	//if all process is complete then break from while
        int done = 1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;
                break;
            }
        }
        if (done) break;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
    printf("\nAverage waiting time: %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
    printf("Average response time: %f\n", (float)total_response_time / n);
    throughput = (float)n / time;
    printf("Throughput: %f processes per unit time\n", throughput);
}

int main() {
    int n, i, algorithm_choice,end=-1;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESS];
    printf("\nEnter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        processes[i].pid = i + 1;
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

while(end!=0){
    printf("\nSelect algorithm:\n");
    printf("1. Non-preemptive SJF\n");
    printf("2. Preemptive SJF\n");
    printf("3. End\n");
    scanf("%d", &algorithm_choice);
    

    if (algorithm_choice == 1) {
        non_preemptive_sjf(n, processes);
    } else if (algorithm_choice == 2) {
        preemptive_sjf(n, processes);
    }else if (algorithm_choice == 3) {
    	end=0;
        //preemptive_sjf(n, processes);
    }  
    else {
        printf("Invalid choice\n");
    }
}
    return 0;
}
