#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
 pid_t pb,pc,pd,pe,pf,pg,ph,pi;
 printf("PROCESS A :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 pb=fork();
 wait(NULL);
 if(pb<0)
 {
 printf("No child process is created\n");
 }
 else if(pb==0)
 {
 printf("PROCESS B :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 pd=fork();
 wait(NULL);
 if(pd<0)
 {
 printf("No child process is created\n");
 }
 else if(pd==0)
 {
 printf("PROCESS D :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 ph=fork();
 wait(NULL);
 if(ph<0)
 {
 printf("No child process is created\n");
 }
 else if(ph==0)
 {
 printf("PROCESS H :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 pi=fork();
 wait(NULL);
 if(pi<0)
 {
 printf("No child process is created\n");
 }
 else if(pi==0)
 {
 printf("PROCESS I :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 exit(0);
 }
 exit(0);
 }
 }
 else
 {
 pe=fork();
 wait(NULL);
 if(pe<0)
 {
 printf("No child process is created\n");
 }
 else if(pe==0)
 {
 printf("PROCESS E :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 exit(0);
 }
 pf=fork();
 wait(NULL);
 if(pf<0)
 {
 printf("No child process is created\n");
 }
 else if(pf==0)
 {
 printf("PROCESS F :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 exit(0);
 }
 exit(0);
 }
 }
else
{
 pc=fork();
 wait(NULL);
 if(pc<0)
 {
 printf("No child process is created\n");
 }
 else if(pc==0)
 {
 printf("PROCESS C :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 pg=fork();
 wait(NULL);
 if(pg<0)
 {
 printf("No child process is created\n");
 }
 else if(pg==0)
 {
 printf("PROCESS G :\n");
 printf("PROCESS ID : %d\n",getpid());
 printf("Parent Process ID : %d\n",getppid());
 exit(0);
 }
 exit(0);
 }
 }
} 