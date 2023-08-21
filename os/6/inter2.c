#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define max 100
struct Student
 {
 char name[50];
 int marks;
 int rank;
 };
void calculate_rank(struct Student students[], int n)
 {
 for (int i = 0; i < n; i++)
 {
 students[i].rank = 1;
 for (int j = 0; j < n; j++)
 {
 if (students[j].marks > students[i].marks)
 students[i].rank++;
 }
 }
 }
void main()
 {
 int n;
 printf("Enter the number of students: ");
 scanf("%d", &n);
 if (n > max)
 {
 printf("Memory limit exceeded\n");
 return;
 }
 key_t key = ftok(".", 'R');
 int shm_id = shmget(key, sizeof(struct Student) * max, IPC_CREAT | 0666);
 struct Student *students = (struct Student *)shmat(shm_id, NULL, 0);
 pid_t pid = fork();
 if (pid < 0)
 {
 printf("Fork failed\n");
 return;
 }
 if (pid == 0)
 {
 printf("Process 1:\n");
 printf("Enter student details:\n");
 for (int i = 0; i < n; i++)
 {
 printf("Student %d:\n", i + 1);
 printf("Name: ");
 scanf("%s", students[i].name);
 printf("Marks: ");
 scanf("%d", &students[i].marks);
 }
 calculate_rank(students, n);
 printf("Student details and ranks stored in shared memory.\n");
 shmdt(students);
 }
 else
 {
 wait(NULL);
 printf("Process 2:\n");
 printf("Rank details of students:\n");
 printf("Name\t\tMarks\tRank\n");
 for (int i = 0; students[i].marks != 0 && i < max; i++)
 printf("%s\t\t%d\t\t%d\n", students[i].name, students[i].marks, students[i].rank);
 shmdt(students);
 }
 }
