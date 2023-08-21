#include <stdio.h>
#include <stdlib.h>
int arr[100],sorted[100];
int l,u,n,head,temp,index;

void sstf()
 {
 int shortest[100];
 int seek_time=0;
 int count=0;
 int headv=head;
 for (int i=0;i<n;i++)
 shortest[i]=arr[i];
 printf("SSTF Scheduling:\n");
 printf("%d-",head);
 while(count!=n)
 {
 int min=10000,d,newindex;
 for(int i=0;i<n+1;i++)
 {
 d=abs(shortest[i]-headv);
 if(min>d)
 {
 min=d;
 newindex=i;
 }

 }
 printf("%d-",shortest[newindex]);
 seek_time+=min;
 headv=shortest[newindex];
 shortest[newindex]=10000;
 count++;
 }
 printf("\n");
 printf("The total seek time is %d\n",seek_time);
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




 sstf();
 
 
 }
