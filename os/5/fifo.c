#include <stdio.h>
#define MAX_PAGES 100
#define MAX_FRAMES 15
void fifo(int pages[], int n, int frames);


int main() 
{
 int choice, n, frames;
 int pages[MAX_PAGES];
 printf("Enter the number of pages: ");
 scanf("%d", &n);
 printf("Enter the page reference string: ");
 for (int i = 0; i < n; i++) 
{
 scanf("%d", &pages[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d", &frames);

 printf("FIFO\n");

 fifo(pages, n, frames);
 
 return 0;
}

void fifo(int pages[], int n, int frames) {
 int frame[MAX_FRAMES] = {0};
 int front = 0, rear = 0;
 int page_faults = 0, hits = 0;
 printf("\nFIFO Page Replacement Algorithm:\n");
 for (int i = 0; i < n; i++) {
 int page = pages[i];
 int found = 0;
 for (int j = 0; j < frames; j++) {
 if (frame[j] == page) {
 found = 1;
 hits++;
 break;
 }
 }
 if (found == 0) {
 frame[rear] = page;
 rear = (rear + 1) % frames;
 page_faults++;
 }
 printf("Page %d -> [", page);
 for (int j = 0; j < frames; j++) {
 printf("%d ", frame[j]);
 }
 printf("]");
 if (found == 0) {
 printf(" (Page Fault)");
 }
 printf("\n");
 }
 printf("\nPage Faults: %d\n", page_faults);
 printf("Hit Ratio: %.2f\n", (float)hits / n);
 printf("Miss Ratio: %.2f\n", 1 - (float)hits / n);
}
