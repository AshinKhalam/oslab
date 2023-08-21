void main()
{
 pid_t b,c,d;
 //printf("\nPARENT\n");
 b=fork();
 if(b==0)
 {
 sleep(3);
 printf("\nPID OF B :- %d",getpid());
 printf("\nParent PID :- %d",getppid());
 }
 else
 {
 c=fork();
 if(c==0)
 {
 sleep(2);
 printf("\nPID OF C :- %d",getpid());
 printf("\nParent PID :- %d",getppid());
 }
 else
 {
 d=fork();
 if(d==0)
 {
 printf("\nPID OF D :- %d",getpid());
 printf("\nParent PID :- %d",getppid());
 }
 else
 {
 sleep(4);
 printf("\nPID OF A :- %d",getpid());
 printf("\nParent PID :- %d",getppid());
 }
 }
}
}