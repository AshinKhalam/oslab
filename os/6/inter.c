#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#define MAX_STUDENTS 100
typedef struct {
 char name[50];
 int marks;
} Student;
void calculate_ranks(Student students[], int numStudents);
int main() {
 int shmid;
 key_t key = ftok("shared_memory", 65);
 int numStudents;
 printf("Enter the number of students: ");
 scanf("%d", &numStudents);
 // Creating shared memory segment
 shmid = shmget(key, sizeof(Student) * numStudents, IPC_CREAT | 0666);
 if (shmid == -1) {
 perror("shmget");
 exit(1);
 }
 // Attach the shared memory segment to the parent process
 Student* students = (Student*)shmat(shmid, NULL, 0);
 if (students == (Student*)-1) {
 perror("shmat");
 exit(1);
 }
 // Read student details
 printf("Enter details of students:\n");
 for (int i = 0; i < numStudents; i++) {
 printf("Student %d\n", i + 1);
 printf("Name: ");
 scanf("%s", students[i].name);
 printf("Marks: ");
 scanf("%d", &students[i].marks);
 }
 // Create a child process using fork
 pid_t pid = fork();
 if (pid == 0) {
 // Child process - display rank details
 sleep(2); // Wait for parent to finish writing student details
 printf("\nRank Details:\n");
 calculate_ranks(students, numStudents);
 // Detach the shared memory segment from the child process
 shmdt(students);
 } else if (pid > 0) {
 // Parent process - continue with other tasks
 // The parent will wait for the child to finish
 wait(NULL);
 // Detach the shared memory segment from the parent process
 shmdt(students);
 // Destroy the shared memory segment
 shmctl(shmid, IPC_RMID, NULL);
 } else {
 perror("fork");
 exit(1);
 }
 return 0;
}
void calculate_ranks(Student students[], int numStudents) {
 // Bubble sort to rank the students based on marks
 for (int i = 0; i < numStudents - 1; i++) {
 for (int j = 0; j < numStudents - i - 1; j++) {
 if (students[j].marks < students[j + 1].marks) {
 // Swap students[j] and students[j+1]
 Student temp = students[j];
 students[j] = students[j + 1];
 students[j + 1] = temp;
 }
 }
 }
 // Display the ranked students
 for (int i = 0; i < numStudents; i++) {
 printf("Rank %d: %s (%d marks)\n", i + 1, students[i].name, students[i].marks);
 }
}
