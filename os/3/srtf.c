#include<stdio.h>
#include<stdbool.h>
typedef struct process{
int PID ;
int arrivalTime ;
int burstTime ;
int waitingTime ;
int turnAroundTime ;
int timeLeft ;
bool completed ;
}process ;
typedef struct ganttChart{
int PID ;
int timeValue ;
}ganttChart ;
void nonPremptive(process ps1[], int numberOfProcess){
for(int i = 0 ; i < numberOfProcess - 1 ; i++){
for(int j = 0 ; j < numberOfProcess - i - 1 ; j++){
if(ps1[j].arrivalTime > ps1[j + 1].arrivalTime){
process temp = ps1[i] ; ps1[i] = ps1[i + 1] ; ps1[i + 1] = temp ;
} }
}
int i = 0 ;
int timeElapsed = ps1[0].arrivalTime ;
while(i < numberOfProcess){
int minIndex = -1 ;
int minBurstTime = 10000 ;
for(int j = i ; j < numberOfProcess ; j++){
if(ps1[j].arrivalTime <= timeElapsed && ps1[j].burstTime <= minBurstTime){
minIndex = j ;
minBurstTime = ps1[j].burstTime ;
}
}
if(minIndex != -1){
process temp = ps1[i] ; ps1[i] = ps1[minIndex] ; ps1[minIndex] = temp ;
}
timeElapsed += ps1[i].burstTime ; i++ ;
}
ganttChart chart1[100] ;
int sumOfWT = 0 ;
int sumOfTAT = 0 ;
timeElapsed = ps1[0].arrivalTime ;
for(i = 0 ; i < numberOfProcess ; i++){
chart1[i].PID = ps1[i].PID ;
chart1[i].timeValue = timeElapsed ;
ps1[i].waitingTime = timeElapsed - ps1[i].arrivalTime ;
sumOfWT += ps1[i].waitingTime ;
timeElapsed += ps1[i].burstTime ;
ps1[i].turnAroundTime = ps1[i].burstTime + ps1[i].waitingTime ;
sumOfTAT += ps1[i].turnAroundTime ;
}
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n") ;
for(i = 0; i < numberOfProcess ; i++){
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", ps1[i].PID, ps1[i].arrivalTime, ps1[i].burstTime, ps1[i].waitingTime, ps1[i].turnAroundTime) ;
}
printf("Gantt Chart :-\n") ;
for(i = 0; i < numberOfProcess ; i++){
printf("|\tP%d\t", chart1[i].PID) ;
}
printf("|\n") ;
for(i = 0; i < numberOfProcess ; i++){
printf("%d\t\t", chart1[i].timeValue) ;
}
printf("%d\n", timeElapsed) ;
printf("The average waiting is %.2f unit\n",(float) sumOfWT / numberOfProcess) ;
printf("The average turn around time is %.2f unit\n", (float) sumOfTAT / numberOfProcess) ;
printf("Throughput of the system is %.2f\n", (float) numberOfProcess / timeElapsed) ;
}
void premptive(process ps2[], int numberOfProcess){
int noOfCompleted = 0 ;
for(int i = 0 ; i < numberOfProcess - 1 ; i++){
for(int j = 0 ; j < numberOfProcess - i - 1 ; j++){
if(ps2[j].arrivalTime > ps2[j + 1].arrivalTime){
process temp = ps2[i] ; ps2[i] = ps2[i + 1] ; ps2[i + 1] = temp ;
} }
}
ganttChart chart1[100] ;
int chartIndex = 0 ;
int sumOfWT = 0 ;
int sumOfTAT = 0 ;
int timeElapsed = ps2[0].arrivalTime ; int i = 0 ;
while(i < numberOfProcess){
int minIndex = -1 ;
int minTimeLeft = 10000 ;
for(int j = 0 ; j < numberOfProcess ; j++){
if(ps2[j].arrivalTime <= timeElapsed && ps2[j].timeLeft <= minTimeLeft && !
ps2[j].completed){
minIndex = j ;
minTimeLeft = ps2[j].burstTime ; }
}
if(minIndex != -1){
chart1[chartIndex].PID = ps2[minIndex].PID ;
chart1[chartIndex].timeValue = timeElapsed ; chartIndex++ ;
timeElapsed++ ;
ps2[minIndex].timeLeft-- ; if(ps2[minIndex].timeLeft == 0){
ps2[minIndex].completed = true ;
ps2[minIndex].turnAroundTime = timeElapsed - ps2[minIndex].arrivalTime ;
ps2[minIndex].waitingTime = ps2[minIndex].turnAroundTime -
ps2[minIndex].burstTime ;
sumOfWT += ps2[minIndex].waitingTime ;
sumOfTAT += ps2[minIndex].turnAroundTime ; i++ ;
}
} else{
timeElapsed++ ; }
}
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n") ; 
for(int i = 0; i< numberOfProcess ; i++){
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", ps2[i].PID, ps2[i].arrivalTime, ps2[i].burstTime,ps2[i].waitingTime, ps2[i].turnAroundTime) ;
}
ganttChart chart[100] ;
chart[0].PID = chart1[0].PID ;
chart[0].timeValue = chart1[0].timeValue ; int k = 1 ;
for(int i = 1 ; i < chartIndex ; i++){
if(chart1[i].PID == chart1[i - 1].PID){ continue ;
}
chart[k].PID = chart1[i].PID ;
chart[k].timeValue = chart1[i].timeValue ; k++ ;
}
printf("Gantt Chart :-\n") ; for(int i = 0; i < k ; i++){
printf("|\tP%d\t", chart[i].PID) ;
}
printf("|\n") ;
for(int i = 0; i < k ; i++){
printf("%d\t\t", chart[i].timeValue) ;
}
printf("%d\n", timeElapsed) ;
printf("The average waiting is %.2f unit\n",(float) sumOfWT / numberOfProcess) ; 
printf("The average turn around time is %.2f unit\n", (float) sumOfTAT / numberOfProcess) ;
printf("Throughput of the system is %.2f\n", (float) numberOfProcess / timeElapsed) ;
}
void main(){
int numberOfProcess ;
printf("Input number of Process :- ") ;
scanf("%d", &numberOfProcess) ; process ps1[100] ;
process ps2[100] ;
for(int i = 0 ; i < numberOfProcess ; i++){
printf("Process %d :- \n", i + 1) ;
printf("Input Arrival and Burst Time :- ") ;
scanf("%d %d", &ps1[i].arrivalTime, &ps1[i].burstTime) ; ps1[i].PID = i + 1 ;
ps1[i].completed = false ;
ps1[i].timeLeft = ps1[i].burstTime ;
ps2[i] = ps1[i] ;
}
printf("---------------------------\n") ;
printf("Non Premptive Scheduling\n") ; 
nonPremptive(ps1, numberOfProcess) ; 
printf("---------------------------\n") ; 
printf("Premptive Scheduling\n") ; 
premptive(ps2, numberOfProcess) ;
printf("---------------------------\n") ; }
