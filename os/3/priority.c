#include "stdio.h"
#define NPROCESS 7
#define INF 999
void RestoreRemainingTime(int RemainingTime[], int CopyRemainingTime[])
{
for(int i=0;i<NPROCESS;i++)
{
RemainingTime[i] = CopyRemainingTime[i];
}
}
void NonPre_emption(int ShortestArrivalIndex,int RemainingTime[],int Process[][4], int Priority[])
{
int Completed = 0;
int time;
int CT[NPROCESS];
int TAT[NPROCESS];
int WT[NPROCESS];
int RT[NPROCESS];
int Flag[] = {0,0,0,0,0,0,0};
//Execute the first arriving process completeley
time = Process[ShortestArrivalIndex][2] + RemainingTime[ShortestArrivalIndex];
RemainingTime[ShortestArrivalIndex] = 0;
printf("%d\t",Process[ShortestArrivalIndex][0]);
CT[ShortestArrivalIndex] = Process[ShortestArrivalIndex][2] + Process[ShortestArrivalIndex]
[3];
TAT[ShortestArrivalIndex] = CT[ShortestArrivalIndex] - Process[ShortestArrivalIndex][2];
WT[ShortestArrivalIndex] = TAT[ShortestArrivalIndex] - Process[ShortestArrivalIndex][3];
RT[ShortestArrivalIndex] = 0;
Completed = 1;
while(Completed <= NPROCESS - 1 )
{
int ShortestIndex = -1;
int ShortestPriority = INF;int PreviousShortestIndex;
for(int i=0;i<NPROCESS;i++)
{
if(Process[i][2] <= time && RemainingTime[i] != 0)
{
//Find the Process with highest priority(Least numerical value)
if(Priority[i] < ShortestPriority)
{
ShortestIndex = i;
ShortestPriority = Priority[ShortestIndex];
Flag[ShortestIndex] = 1;
}
}
}
if(ShortestIndex != -1)
{
time = time + RemainingTime[ShortestIndex];
RemainingTime[ShortestIndex] = 0 ;
if(RemainingTime[ShortestIndex] == 0 && Flag[ShortestIndex] == 1)
{
Flag[ShortestIndex] = 0;
printf("%d\t",Process[ShortestIndex][0]);
Completed++;
//Assigning Completion Time
CT[ShortestIndex] = CT[ShortestArrivalIndex] + Process[ShortestIndex][3];
ShortestArrivalIndex = ShortestIndex;
//Calculating TAT = CT - AT
TAT[ShortestIndex] = CT[ShortestIndex] - Process[ShortestIndex][2];
//Calculating WT = TAT - BT
WT[ShortestIndex] = TAT[ShortestIndex] - Process[ShortestIndex][3];
//Calculating RT = WT (NON PRE-EMPTIVE)
RT[ShortestIndex] = WT[ShortestIndex];
}
}
time++;}
//Average CT TAT WT RT
float CTSum = 0;
float
TATSum = 0;
float WTSum = 0;
float RTSum = 0;
for(int i=0;i<NPROCESS;i++)
{
CTSum = CTSum + CT[i];
TATSum = TATSum + TAT[i];
WTSum = WTSum + WT[i];
RTSum = RTSum + RT[i];
}
//Print All Parameters
printf("\n");
printf("Process\tP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
for(int i=0;i<NPROCESS;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",Process[i][0],Process[i][1],Process[i][2],Process[i][3],CT[i],TAT[i],WT[i],RT[i]);
}
//Print average CT, TAT, WT 
printf("Average CT =%f\n",CTSum/NPROCESS); 
printf("Average TAT =%f\n",TATSum/NPROCESS); 
printf("Average WT =%f\n",WTSum/NPROCESS); 
printf("Average RT =%f\n",RTSum/NPROCESS);
}
void Pre_emption(int Process[][4],int RemainingTime[], int Priority[])
{
int Completed = 0;
int time = 0;
int CT[NPROCESS];
int TAT[NPROCESS];
int WT[NPROCESS];
int RT[NPROCESS];
int Flag[NPROCESS] = {0,0,0,0,0,0,0}; int
EnteredTimeFlag[NPROCESS] = {0,0,0,0,0,0,0};
while(Completed <= NPROCESS - 1 )
{int ShortestIndex = -1;
int ShortestPriority = INF;
for(int i=0;i<NPROCESS;i++)
{
if(Process[i][2] <= time && RemainingTime[i] != 0)
{
//Find the Process with Highest Priority (Least numerical value)
if(Priority[i] < ShortestPriority)
{
ShortestIndex = i;
ShortestPriority = Priority[ShortestIndex];
Flag[ShortestIndex] = 1;
}
}
}
if(ShortestIndex != -1)
{
RemainingTime[ShortestIndex] = RemainingTime[ShortestIndex] - 1 ;
//To Find the first time slice in which the process started to execute.
int FirstEnteredTime;
if(EnteredTimeFlag[ShortestIndex] == 0)
{
FirstEnteredTime = time;
EnteredTimeFlag[ShortestIndex] = 1;
//Calculating RT = First Entered Time - AT
RT[ShortestIndex] = FirstEnteredTime - Process[ShortestIndex][2];
}
if(RemainingTime[ShortestIndex] == 0 && Flag[ShortestIndex] == 1)
{
Flag[ShortestIndex] = 0;
printf("%d\t",Process[ShortestIndex][0]);
Completed++;
//Assigning Completion Time
CT[ShortestIndex] = time + 1;
//Calculating TAT = CT - AT
TAT[ShortestIndex] = CT[ShortestIndex] - Process[ShortestIndex][2];
//Calculating WT = TAT - BT
WT[ShortestIndex] = TAT[ShortestIndex] - Process[ShortestIndex][3];}
}
time++;
}
//Average CT TAT WT RT
float CTSum = 0;
float
TATSum = 0;
float WTSum = 0;
float RTSum = 0;
for(int i=0;i<NPROCESS;i++)
{
CTSum = CTSum + CT[i];
TATSum = TATSum + TAT[i];
WTSum = WTSum + WT[i];
RTSum = RTSum + RT[i];
}
//Print All Parameters
printf("\n");
printf("Process\tP\tAT\tBT\tCT\tTAT\tWT\tRT\n\n");
for(int i=0;i<NPROCESS;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",Process[i][0],Process[i][1],Process[i]
[2],Process[i][3],CT[i],TAT[i],WT[i],RT[i]);
}
//Print average CT, TAT, WT 
printf("Average CT =%f\n",CTSum/NPROCESS); 
printf("Average TAT =%f\n",TATSum/NPROCESS); 
printf("Average WT =%f\n",WTSum/NPROCESS); 
printf("Average RT =%f\n",RTSum/NPROCESS);
}
void main() { int
Process[NPROCESS][4]; int
ShortestArrivalIndex = INF; int
RemainingTime[NPROCESS]; int
Priority[NPROCESS];
int CopyRemainingTime[NPROCESS];
int i,j;
for(i=0;i<NPROCESS;i++)
{
for(j=0;j<4;j++){
if(j == 0)
{
printf("Enter the process:");
scanf("%d",&Process[i][j]);
}
else if(j == 1)
{
printf("Enter the Priority:");
scanf("%d",&Process[i][j]);
Priority[i] = Process[i][j];
}
else if(j == 2)
{
printf("Enter the Arrival Time:");
scanf("%d",&Process[i][j]);
if(Process[i][j] <= ShortestArrivalIndex)
{
ShortestArrivalIndex = i;
}
}
else
{
printf("Enter the Burst Time:");
scanf("%d",&Process[i][j]);
RemainingTime[i] = Process[i][j];
CopyRemainingTime[i] = RemainingTime[i];
}
}
}
int Choice = 1;
while(Choice >=1 && Choice <=2)
{
printf("\n1:Priority(Non Pre-emption)\n");
printf("2:Priority(Pre-emption)\n");
printf("Enter the choice:");
scanf("%d",&Choice);
switch (Choice)
{
case 1: RestoreRemainingTime(RemainingTime,CopyRemainingTime);
NonPre_emption(ShortestArrivalIndex, RemainingTime, Process, Priority);
break;
case 2: RestoreRemainingTime(RemainingTime,CopyRemainingTime);Pre_emption(Process, RemainingTime, Priority);
break;
default:Choice = 3;
break;
}
}
}
