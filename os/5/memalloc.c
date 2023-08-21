#include <stdio.h>
#define MAX_PARTITIONS 10
typedef struct 
{
	 int size;
	 int allocated;
} Partition;

void initialize_partitions(Partition partitions[], int n_partitions) 
{
	 for (int i = 0; i < n_partitions; i++) 
	 {
		 partitions[i].size = 0;
		 partitions[i].allocated = 0;
	 }
}
void display_partitions(Partition partitions[], int n_partitions) 
{
	 printf("\nPartition\tSize\tAllocated\n");
	 for (int i = 0; i < n_partitions; i++) 
	 {
	 	printf("%d\t\t%d\t%d\n", i, partitions[i].size, partitions[i].allocated);
	 }
	 printf("\n");
	}

int first_fit(Partition partitions[], int n_partitions, int process_size) 
{
	 for (int i = 0; i < n_partitions; i++) 
	 {
		 if (!partitions[i].allocated && partitions[i].size >= process_size) 
		 {
			 partitions[i].allocated = 1;
			 return i;
		 }
	 }
	 return -1; // No suitable partition found
}

int best_fit(Partition partitions[], int n_partitions, int process_size) 
{
	 int best_partition = -1;
	 int min_fragmentation = -1;
	 for (int i = 0; i < n_partitions; i++) 
	 {
		 if (!partitions[i].allocated && partitions[i].size >= process_size) 
		 {
		 	int fragmentation = partitions[i].size - process_size;
			 if (best_partition == -1 || fragmentation < min_fragmentation) 
			 {
			 best_partition = i;
			 min_fragmentation = fragmentation;
		 	 }
		 }
	 }
	 if (best_partition != -1) 
	 {
	 	partitions[best_partition].allocated = 1;
	 }
	 return best_partition;
}


int worst_fit(Partition partitions[], int n_partitions, int process_size) 
{
	 int worst_partition = -1;
	 int max_fragmentation = -1;
	 for (int i = 0; i < n_partitions; i++) 
 	 {
		 if (!partitions[i].allocated && partitions[i].size >= process_size) 
		 {
		 	int fragmentation = partitions[i].size - process_size;
		 	if (worst_partition == -1 || fragmentation > max_fragmentation) 
		 	{
				 worst_partition = i;
				 max_fragmentation = fragmentation;
			}
		 }
	 }
	 if (worst_partition != -1) 
	 {
		 partitions[worst_partition].allocated = 1;
	 }
	 return worst_partition;
}

int main() 
{
	 Partition partitions[MAX_PARTITIONS];
	 int n_partitions;
	 int process_size;
	 int option;
	
	 printf("Enter the number of partitions: ");
	 scanf("%d", &n_partitions);
	 initialize_partitions(partitions, n_partitions);
	
	
	 // Read partition sizes
	 printf("Enter the sizes of partitions:\n");
	 for (int i = 0; i < n_partitions; i++) 
	 {
		 scanf("%d", &partitions[i].size);
	 }
	 
	do 
	{
		 printf("\n---- Memory Allocation Menu ----\n");
		 printf("1. First Fit\n");
		 printf("2. Best Fit\n");
		 printf("3. Worst Fit\n");
		 printf("4. Exit\n");
		 printf("Enter your option: ");
		 scanf("%d", &option);
		 
		switch (option) 
		{
		 case 1:
			 printf("Enter the size of the process: ");
			 scanf("%d", &process_size);
			 int first_fit_partition = first_fit(partitions, n_partitions, process_size);
			 if (first_fit_partition != -1) 
			 {
				printf("Process allocated to partition %d.\n", first_fit_partition);
			 } 
			 else 
			 {
			 	printf("No suitable partition found for the process.\n");
			 }
			 break;

		 case 2:
			 printf("Enter the size of the process: ");
			 scanf("%d", &process_size);
			 int best_fit_partition = best_fit(partitions, n_partitions, process_size);
			 if (best_fit_partition != -1) 
			 {
				 printf("Process allocated to partition %d.\n", best_fit_partition);
			 }
			 else 
			 {
				 printf("No suitable partition found for the process.\n");
			 }
			 break;

		 case 3:
			 printf("Enter the size of the process: ");
			 scanf("%d", &process_size);
			 int worst_fit_partition =worst_fit(partitions, n_partitions, process_size);
			 if (worst_fit_partition != -1) 
			 {
				 printf("Process allocated to partition %d.\n", worst_fit_partition);
			 } 
			 else 
			 {
				 printf("No suitable partition found for the process.\n");
			 }
			 break;
		 case 4:
		 	printf("Exit\n");
			 break;
		 default:
		 	printf("Invalid option\n");
		 	break;
		 }
		 display_partitions(partitions, n_partitions);

	 } while (option != 4);
	 
	// memory wastage due to internal fragmentation
	 int total_fragmentation = 0;
	 for (int i = 0; i < n_partitions; i++) 
	 {
		 if (!partitions[i].allocated) 
		 {
		 	total_fragmentation += partitions[i].size;
		 }
	 }
	 printf("\nMemory Wastage due to Internal Fragmentation: %d\n",total_fragmentation);
	 return 0;
}
