#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdbool.h>
void main()
{
 int n;
 printf("Enter a number\t");
 scanf("%d",&n);
 int a=fork();
 int i,x=0,y=1,z=0,f=0,j;
 if(a==0)
 {
 printf("\nCHILD PROCESS\n");
 printf("\nFibonacci series\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",z);
 x=y;y=z;z=x+y;
 }
 }
 else if(a>0)
 {
 wait(NULL);
 printf("\n\nPARENT PROCESS\n");
 printf("\n#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdbool.h>
void main()
{
 int n;
 printf("Enter a number\t");
 scanf("%d",&n);
 int a=fork();
 int i,x=0,y=1,z=0,f=0,j;
 if(a==0)
 {
 printf("\nCHILD PROCESS\n");
 printf("\nFibonacci series\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",z);
 x=y;y=z;z=x+y;
 }
 }
 else if(a>0)
 {
 wait(NULL);
 printf("\n\nPARENT PROCESS\n");
 printf("\nPrime Numbers\n");
 bool isPrime(int n)
 {
for (int i = 2; i < n; i++)
if (n % i == 0)
return false;
return true;
 }
 for (int i = 2; i <= n; i++)
 {
 if (isPrime(i))
 printf("%d\t", i);
 }
 printf("\n");
 }
} Prime Numbers\n");
 bool isPrime(int n)
 {
for (int i = 2; i < n; i++)
if (n % i == 0)
return false;
return true;
 }
 for (int i = 2; i <= n; i++)
 {
 if (isPrime(i))
 printf("%d\t", i);
 }
 printf("\n");
 }
} 