#include <stdio.h>
#define MAX_PAGES 100
#define MAX_FRAMES 15
void lru(int pages[], int n, int frames);


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

 printf("LRU\n");

 lru(pages, n, frames);
 
 return 0;
}


void lru(int pages[], int n, int frames) {
 int frame[MAX_FRAMES] = {0};
 int page_faults = 0, hits = 0;
 int count[MAX_FRAMES] = {0};
 printf("\nLRU Page Replacement Algorithm:\n");
 for (int i = 0; i < n; i++) {
 int page = pages[i];
 int found = 0;
 for (int j = 0; j < frames; j++) {
 if (frame[j] == page) {
 found = 1;
 hits++;
 count[j] = i + 1;
 break;
 }
 }
 if (found == 0) {
 int min = count[0];
 int pos = 0;
 for (int j = 1; j < frames; j++) {
 if (count[j] < min) {
 min = count[j];
 pos = j;
 }
 }
 frame[pos] = page;
 count[pos] = i + 1;
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

