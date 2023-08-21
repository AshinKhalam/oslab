#include "stdio.h"
#define MAX 200
int MakePositive(int Difference)
{
if(Difference < 0)
{
Difference = -1 * Difference;
}
return Difference;
}
void InitialiseTrack(int Track[])
{
//initialising all the track indices with value 0 to symbolise all are empty.
for(int i=0;i<MAX;i++)
{
Track[i] = 0;
}
}
void FCFSDisk(int Track[], int TrackOrder[],int TrackCount)
{
int Head;
int Difference;
int Sum = 0;
printf("Enter the index in which Head should start:");
scanf("%d",&Head);
//Finding the Tracks with respect to the order given.
for(int i=0;i<TrackCount;i++)
{
for(int j=0;j<MAX;j++)
{
if(TrackOrder[i] == j && Track[j] == 1)
{
Difference = Head - j;
Sum = Sum + MakePositive(Difference);Head = j;
break;
}
}
}
printf("Sum = %d\n",Sum);
}
void main()
{
int Track[MAX];
int TrackIndex;
int
TrackCount; int
TrackOrder[50];
InitialiseTrack(Track);
printf("Enter the number of tracks:");
scanf("%d",&TrackCount);
int Count = 0;
for(int i=0;i<MAX;i++)
{
//If the count is less than the total track you want to insert then only do the insertion
if(Count < TrackCount)
{
//setting the track index in track array to value 1 others are left 0
//Also using extra array named TrackOrder to find the order in which the tracks are input.
printf("Enter Track:");
scanf("%d",&TrackIndex);
Track[TrackIndex] = 1;
TrackOrder[i] = TrackIndex;
Count++;
}
else
{
break;
}
}
printf("Track Order :\n");
for(int i=0;i<TrackCount;i++)
{
printf("%d : %d\n",i,TrackOrder[i]);
}FCFSDisk(Track, TrackOrder, TrackCount);
}
