#include<stdio.h>
void FCFS(int p[],int bt[],int wt[],int tat[],int n)
{
int wsum1=0,tsum1=0;
int i,j;
wt[0]=0;
printf("Calculating waiting time:\n");
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
wsum1=wsum1+wt[i];
}
printf("Calculating turnaround time:\n");
for(i=0;i<n;i++)
{
tat[i]=wt[i]+bt[i];
tsum1=tsum1+tat[i];
}
printf("Process\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
}
printf("Average waiting time=%d\n",wsum1/n);
printf("Average turnaround time=%d\n",tsum1/n);
}
void SJF(int p[],int bt[],int wt[],int tat[],int n)
{
int pb[10][2];
int i,j;
int wsum2=0,tsum2=0;
int tempp,tempb;
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
if(j==0)
{
pb[i][j]=p[i];
}
if(j==1){
pb[i][j]=bt[i];
}
}
}
printf("The process and burst time:\n");
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
printf("%d\t",pb[i][j]);
}
printf("\n");
}
printf("Sorting burst time:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(pb[j][1]>pb[j+1][1])
{
tempp=pb[j][0];
pb[j][0]=pb[j+1][0];
pb[j+1][0]=tempp;
tempb=pb[j][1];
pb[j][1]=pb[j+1][1];
pb[j+1][1]=tempb;
}
}
}
printf("The sorted processes and burst time:\n");
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
printf("%d\t",pb[i][j]);
}
printf("\n");
}
wt[0]=0;
printf("Calculating waiting time:\n");
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+pb[i-1][1];wsum2=wsum2+wt[i];
}
printf("Calculating turnaround time:\n");
for(i=0;i<n;i++)
{
tat[i]=wt[i]+pb[i][1];
tsum2=tsum2+tat[i];
}
printf("Process\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\n",pb[i][0],pb[i][1],wt[i],tat[i]);
}
printf("Average waiting time=%d\n",wsum2/n);
printf("Average turnaround time=%d\n",tsum2/n);
}
void main()
{ int n,i,choice=1; int
p[10]; int
wt[10],bt[10],tat[10];
printf("Enter the value to n:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the process:\n");
scanf("%d",&p[i]);
printf("Enter the burst time:\n");
scanf("%d",&bt[i]);
}
while(choice>=1 && choice<=2)
{
printf("CPU SCHEDULING:\n");
printf("1:FCFS\n");
printf("2:SJF\n");
printf("................\n");
printf("Enter the choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("FCFS\n");
FCFS(p,bt,wt,tat,n);
break;
case 2: SJF(p,bt,wt,tat,n);break;
default: choice=3;
break;
}
}
}
