#include <stdio.h>
#include <stdlib.h>
int arr[100],sorted[100];
int l,u,n,head,temp,index;

void fcfs()
 {
 int seek_time=0;
 printf("FCFS Scheduling:\n");
 printf("%d-",head);
 for (int i=0;i<n;i++)
 {
 printf("%d-",arr[i]);
 }
 printf("\n");
 seek_time=abs(arr[0]-head);
 for (int i=0;i<n-1;i++)
 seek_time+=abs(arr[i+1]-arr[i]);
 printf("The total seek time is: %d\n",seek_time);
 }

void main()
 {
 int choice;

 printf("Enter the lower and upper limits of the disk\n");
 scanf("%d %d",&l,&u);
 printf("Enter the number of requests: (max:100)\n");
 scanf("%d",&n);
 printf("Enter %d requests:\n",n);
 for (int i=0;i<n;i++)
 	scanf("%d",&arr[i]);
 printf("Enter the head value:\n");
 scanf("%d",&head);
 for (int i=0;i<n;i++)
 	sorted[i]=arr[i];
 sorted[n]=head;
 for (int i=0;i<n+1;i++)
 {
	 for (int j=0;j<n-i;j++)
	 {
		 if (sorted[j]>sorted[j+1])
		 {
			 temp=sorted[j];
			 sorted[j]=sorted[j+1];
			 sorted[j+1]=temp;
		 }
	 }
 }
 for (int i=0;i<n+1;i++)
 {
	if (sorted[i]==head)
 	index=i;
 }




 fcfs();
 
 
 }
