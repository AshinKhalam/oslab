#include "stdio.h"
#include "sys/wait.h"
#include "unistd.h"
#include "stdlib.h"
void main()
{
pid_t id1,id2,id3;
id1 = fork();
if(id1 == 0)
{
sleep(3); 
printf("Child 1 executing\n");
printf("Child 1 terminating\n");
exit(0);
}
else
{
id2 = fork();
if(id2 == 0)
{
sleep(2); 
printf("Child 2 executing\n");
printf("Child 2 terminating\n");
exit(0);
}
else
{
id3 = fork();
if(id3 == 0)
{
printf("Child 3 executing\n");
printf("Child 3 terminating\n");
exit(0);
}
}
sleep(4);
printf("Parent executing\n");
printf("Parent terminating\n");
exit(0);
}
}
