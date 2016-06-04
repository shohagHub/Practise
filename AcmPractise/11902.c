
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
//     int j;
//     for (j=0; j<N; j++) {
//          if (fused[j] && !used[j])
//              Ans[i][j] = 1;
     }
