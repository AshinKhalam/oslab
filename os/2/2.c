#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
pid_t id1; pid_t id2;
pid_t id3; pid_t id4;
pid_t id5; pid_t id6;
pid_t id7; pid_t id8;
id1=fork();
//A and B
if(id1!=0)
{
//A
printf("A id=%d\n",getpid);
id2=fork();
wait(NULL);
if(id2==0)
{
//C
printf("C id=%d\n",getpid);
printf("Parent of C, A id=%d\n",getppid);
id3=fork();
wait(NULL);
if(id3==0)
{
//G
wait(NULL);
printf("G id=%d\n",getpid);
printf("Parent of G, C id=%d\n",getppid);
}
else if(id3!=0)
{
//C
wait(NULL);
printf("C
id=%d\n",getpid);
printf("A id=%d\n",getppid);
//A
wait(NULL);
printf("A id=%d\n",getpid);
}
wait(NULL);
} else
if(id1==0)
{ //B 
wait(NULL); 
printf("B id=%d\n",getpid);
printf("A id=%d\n",getppid); 
id4=fork();
if(id4==0)
{ //D 
wait(NULL); 
printf("D id=%d\n",getpid);
printf("B id=%d\n",getppid); 
id5=fork();
if(id5==0) {
//H
wait(NULL);
printf("H
id=%d\n",getpid);
printf("D id=%d\n",getppid); id6=fork(); 
if(id6==0)
{
//I
wait(NULL);
printf("I id=%d\n",getpid);
printf("H id=%d\n",getppid);
}
else if(id6!=0)
{
//H
wait(NULL); printf("H id=%d\n",getpid); 
printf("D d=%d\n",getppid);
}
}
else if(id5!=0)
{
//D
wait(NULL);
printf("D id=%d\n",getpid);
printf("B id=%d\n",getppid);
}
wait(NULL);
}
else if(id4!=0)
{ //B 
wait(NULL); 
printf("B id=%d\n",getpid);
printf("A id=%d\n",getppid);
id7=fork(); if(id7==0)
{ //E
wait(NULL); 
printf("E id=%d\n",getpid);
printf("B id=%d\n",getppid);
}
else if(id7!=0)
{//B
wait(NULL);
printf("B id=%d\n",getpid);
printf("A id=%d\n",getppid);
id8=fork(); 
if(id8==0)
{
//F
wait(NULL);
printf("F id=%d\n",getpid);
printf("B id=%d\n",getppid);
}
else if(id8!=0)
{
//B
wait(NULL);
printf("B id=%d\n",getpid);
printf("A id=%d\n",getppid);
}
}
wait(NULL);
}
wait(NULL);
}
}
