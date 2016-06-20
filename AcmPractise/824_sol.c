#include<stdio.h>

int X, Y;
int Direction;
int Ans;
 

int in[3][3];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
 

void initCase()
{
     int i, j;
     for (i=0; i<3; i++) for (j=0; j<3; j++)
          in[i][j] = 0;
}
 

void readCase()
{
     int i, xx, yy, td;
     scanf("%d %d", &Y, &Direction);
     for (i=0; i<8; i++) {
          scanf("%d %d %d", &xx, &yy, &td);
          xx -= (X-1);
          yy -= (Y-1);
          in[2-yy][xx] = td;
     }
}
 

void solveCase()
{
     int i, nextX, nextY, pos;
     for (i=0; i<8; i++) {
          pos = (Direction+i+5)%8;
          nextX = 1 + dx[pos];
          nextY = 1 + dy[pos];
          if (in[nextY][nextX]) {
              Ans = pos;
              return;
          }
     }
}
 

void printCase()
{
     printf("%d\n", Ans);
}
 

int main()
{
     while (1 == scanf("%d", &X)) {
          if (-1 == X)
              break;
          initCase();
          readCase();
          solveCase();
          printCase();
     }
     return 0;
}