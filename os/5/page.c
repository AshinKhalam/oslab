#include <stdio.h>
#define MAX_PAGES 100
#define MAX_FRAMES 15
void fifo(int pages[], int n, int frames);
void lru(int pages[], int n, int frames);
void lfu(int pages[], int n, int frames);
void optimal(int pages[], int n, int frames);
int main() {
 int choice, n, frames;
 int pages[MAX_PAGES];
 printf("Enter the number of pages: ");
 scanf("%d", &n);
 printf("Enter the page reference string: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &pages[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d", &frames);
 printf("\nPage Replacement Algorithms:\n");
 printf("1. FIFO\n");
 printf("2. LRU\n");
 printf("3. LFU\n");
 printf("4. Optimal\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 fifo(pages, n, frames);
 break;
 case 2:
 lru(pages, n, frames);
 break;
 case 3:
 lfu(pages, n, frames);
 break;
 case 4:
 optimal(pages, n, frames);
 break;
 default:
 printf("Invalid choice!\n");
 break;
 }
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
void lfu(int pages[], int n, int frames) {
 int frame[MAX_FRAMES] = {0};
 int page_faults = 0, hits = 0;
 int count[MAX_FRAMES] = {0};
 printf("\nLFU Page Replacement Algorithm:\n");
 for (int i = 0; i < n; i++) {
 int page = pages[i];
 int found = 0;
 int min = count[0];
 int pos = 0;
 for (int j = 0; j < frames; j++) {
 if (frame[j] == page) {
 found = 1;
 hits++;
 count[j]++;
 break;
 }
 if (count[j] < min) {
 min = count[j];
 pos = j;
 }
 }
 if (found == 0) {
 frame[pos] = page;
 count[pos] = 1;
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
void optimal(int pages[], int n, int frames) {
 int frame[MAX_FRAMES] = {0};
 int page_faults = 0, hits = 0;
 int pos[MAX_FRAMES] = {-1};
 printf("\nOptimal Page Replacement Algorithm:\n");
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
 int farthest = i;
 int replace = 0;
 for (int j = 0; j < frames; j++) {
 int k;
 for (k = i + 1; k < n; k++) {
 if (frame[j] == pages[k]) {
 if (k > farthest) {
 farthest = k;
 replace = j;
 }
 break;
 }
 }
 if (k == n) {
 replace = j;
 break;
 }
 }
 frame[replace] = page;
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
