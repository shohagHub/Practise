#include<stdio.h>
#define SIZE 1001
#define INF 0xffff
int N;
typedef struct pointStruct
{
int x, y;
}Point;
Point P[SIZE];
void readCase()
{
int i;
for (i=0; i<N; i++)
scanf("%d %d", &P[i].x, &P[i].y);
}
int pointDist(int i, int j)
{
int xdif, ydif;
xdif = P[i].x - P[j].x;
ydif = P[i].y - P[j].y;
return xdif*xdif + ydif*ydif;
}
int Link[SIZE][2];
void searchLink()
{
int i, j;
int min1, min2;
int index1, index2;
int dist;
for (i=0; i<N; i++) {
min1 = min2 = INF;
index1 = index2 = -1;
for (j=0; j<N; j++) if (i != j) {
dist = pointDist(i, j);
if (dist <= min1) {
min2 = min1;
min1 = dist;
index2 = index1;
index1 = j;
}
else if (dist < min2) {
min2 = dist;
index2 = j;
}
}
Link[i][0] = index1;
Link[i][1] = index2;
}
}
int used[SIZE];
void resetUsed()
{
int i;
for (i=0; i<N; i++)
used[i] = 0;
}
int count(int i)
{
if (used[i])
return 0;
used[i] = 1;
return count(Link[i][0]) + count(Link[i][1]) + 1;
}
int Ans;
void solveCase()
{
searchLink();
resetUsed();
Ans = count(0);
}
void printCase()
{
if (Ans == N)
printf("All stations are reachable.\n");
else
printf("There are stations that are unreachable.\n");
}
int main()
{
while (1 == scanf("%d", &N) && N) {
readCase();
solveCase();
printCase();
}
return 0;
}
