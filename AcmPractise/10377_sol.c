#include<stdio.h>
#define SIZE 61
int T;
int Row, Col;
char Maze[SIZE][SIZE];
int X, Y;
void readCase()
{
int i;
scanf("%d %d ", &Row, &Col);
for (i=0; i<Row; i++)
gets(Maze[i]);
scanf("%d %d", &X, &Y);
X--;
Y--;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dir;
int isValid(int r, int c)
{
if (r < 0)
return 0;
if (r == Row)
return 0;
if (c < 0)
return 0;
if (c == Col)
return 0;
if (Maze[r][c] == '*')
return 0;
return 1;
}
void go(char ch)
{
switch (ch) {
case 'L': dir = (dir + 3) % 4; break;
case 'R': dir = (dir + 1) % 4; break;
case 'F':
if (isValid(X + dx[dir], Y + dy[dir])) {
X += dx[dir];
Y += dy[dir];
}
break;
}
}
void solveCase()
{
char ch;
dir = 0;
do {
ch = getchar();
go(ch);
}while (ch != 'Q');
}
void printCase()
{
printf("%d %d %c\n", ++X, ++Y, "NESW"[dir]);
if (T)
printf("\n");
}
int main()
{
scanf("%d", &T);
while (T--) {
readCase();
solveCase();
printCase();
}
return 0;
}

