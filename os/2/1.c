#include "stdio.h"
#include "unistd.h"
#include "limits.h"
#include "sys/wait.h"
void main()
{
int n;
printf("Enter the value to n:");
scanf("%d",&n);
int id = fork();
if(id!=0)
{
int i,j;
int count = 0;
printf("The n prime numbers are:\n");
for(i=2;i<=INT_MAX;i++)
{
int flag=0;
if(count == n)
{
break;
}
for(j=2;j<=(i/2);j++)
{
if(i%j==0)
{
flag=1;
break;
}
}
if(flag==0)
{
printf("%d\t",i);
count++;
}
}
printf("\n");
wait(NULL);
}
else
{wait(NULL);
printf("Fibnocci numbers upto n terms:\n");
int n1=0;
int n2=1;
int sum;
printf("%d\n%d\n",n1,n2);
for(int i=2;i<n;i++)
{
sum=n1+n2;
printf("%d\n",sum);
n1=n2;
n2=sum;
}
}
}
