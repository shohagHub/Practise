#include<stdio.h>
#define SIZE_N 101
#define SIZE_S 50001
int N, M, S;
char Maze[SIZE_N][SIZE_N];
char Ins[SIZE_S];
void readCase()
{
int i;
for (i=0; i<N; i++)
scanf("%s", Maze[i]);
scanf("%s", Ins);
}
int X, Y;
int dir;
void initPosition()
{
int i, j;
for (i=0; i<N; i++) for (j=0; j<M; j++) {
switch (Maze[i][j]) {
case 'N':
X = i;
Y = j;
dir = 0;
return;
case 'L':
X = i;
Y = j;
dir = 1;
return;
case 'S':
X = i;
Y = j;
dir = 2;
return;
case 'O':
X = i;
Y = j;
dir = 3;
return;
}
}
}
int isValid(int x, int y)
{
if (x < 0)
return 0;
if (y < 0)
return 0;
if (x == N)
return 0;
if (y == M)
return 0;
if (Maze[x][y] == '#')
return 0;
return 1;
}
int Ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void traverse()
{
int i;
for (i=0; i<S; i++) {
switch (Ins[i]) {
case 'D':
dir = (dir + 1) % 4;
break;
case 'E':
dir = (dir + 3) % 4;
break;
case 'F':
if (isValid(X + dx[dir], Y + dy[dir])) {
X += dx[dir];
Y += dy[dir];
if ('*' == Maze[X][Y]) {
Ans++;
Maze[X][Y] = '.';
}
}
break;
}
}
}
void solveCase()
{
initPosition();
Ans = 0;
traverse();
}
void printCase()
{
printf("%d\n", Ans);
}
int main()
{
while (3 == scanf("%d %d %d", &N, &M, &S) && (N+M+S)) {
readCase();
solveCase();
printCase();
}
return 0;
}
