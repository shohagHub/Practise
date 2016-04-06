#include<stdio.h>
 

#define SIZE 11
 

charGrid[SIZE][SIZE];
int Row, Col;
int X, Y;
int Step,Loop;
intDepth[SIZE][SIZE];
 

void initCase()
{
      int i, j;
      X = 0;
      Y--;
      for (i=0; i<Row; i++) for (j=0; j<Col; j++)
            Depth[i][j] = 0;
}
 

void readCase()
{
      int i;
      for (i=0; i<Row; i++)
            scanf("%s",Grid[i]);
}
 

int isExit()
{
      if (X < 0)
            return 1;
      if (Y < 0)
            return 1;
      if (X == Row)
            return 1;
      if (Y == Col)
            return 1;
      return 0;
}
 

void go()
{
      Depth[X][Y] = ++Step;
      switch (Grid[X][Y]) {
            case 'N': X--; break;
            case 'S': X++; break;
            case 'E': Y++; break;
            case 'W': Y--; break;
      }
}
 

voidsolveCase()
{
      Step = Loop = 0;
      while (!isExit() &&!Depth[X][Y])
            go();
      if (!isExit()) {
            Loop = Step - Depth[X][Y] + 1;
            Step -= Loop;
      }
}
 

voidprintCase()
{
      if (Loop)
            printf("%d step(s)before a loop of %d step(s)\n", Step, Loop);
      else
            printf("%d step(s) toexit\n", Step);
}
 

int main()
{
      while (3 == scanf("%d %d %d", &Row, &Col, &Y)&& (Row+Col+Y)) {
            initCase();
            readCase();
            solveCase();
            printCase();
      }
      return 0;
}
