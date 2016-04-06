#include<stdio.h>
 

#define SIZE 101
 

int T, N;
int Case;
int Path[SIZE][SIZE];
int Ans[SIZE][SIZE];
 

void readCase()
{
     int i, j;
     scanf("%d", &N);
     for (i=0; i<N; i++) for (j=0; j<N; j++)
          scanf("%d", &Path[i][j]);
}
 

int used[SIZE];
int fused[SIZE];
 

void resetUsed()
{
     int i;
     for (i=0; i<N; i++)
          used[i] = 0;
}
 

void fill(int i)
{
     int j;
     if (used[i])
          return;
     used[i] = 1;
     for (j=0; j<N; j++) if (Path[i][j])
          fill(j);
}
 

void updateAns(int i)
{
     int j;
     for (j=0; j<N; j++) {
          if (fused[j] && !used[j])
              Ans[i][j] = 1;
          else
              Ans[i][j] = 0;
     }
     Ans[i][i] = fused[i];
}
 

void solveRow(int i)
{
     resetUsed();
     used[i] = 1;
     fill(0);
     updateAns(i);
}
 

void solveCase()
{
     int i;
     resetUsed();
     fill(0);
     for (i=0; i<N; i++)
          fused[i] = used[i];
     for (i=0; i<N; i++)
          solveRow(i);
}
 

void drawLine()
{
     int i;
     printf("+");
     for (i=-N+1; i<N; i++)
          printf("-");
     printf("+\n");
}
 

void printCase()
{
     int i, j;
     printf("Case %d:\n", Case);
     drawLine();
     for (i=0; i<N; i++) {
          for (j=0; j<N; j++) {
              printf("|");
              if (Ans[i][j])
                   printf("Y");
              else
                   printf("N");
          }
          printf("|\n");
          drawLine();
     }
}
 

int main()
{
     scanf("%d", &T);
     for (Case=1; Case<=T; Case++) {
          readCase();
          solveCase();
          printCase();
     }
     return 0;
}
 
