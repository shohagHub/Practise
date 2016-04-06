//Solution 1: O(N*N) (Run Time: TLE)
#include<stdio.h>
 

#define SIZE 101
 

int T;
int N, M;
int Case;
int Value[SIZE];
int Path[SIZE][SIZE];
 

void initPath()
{
     int i, j;
     for (i=0;i<N; i++) for (j=0; j<N; j++)
          Path[i][j] = 0;
}
 

void readCase()
{
     int i;
     int x, y;
     scanf("%d%d", &N, &M);
     for (i=0;i<N; i++)
          scanf("%d",&Value[i]);
     for (i=0;i<M; i++) {
          scanf("%d%d", &x, &y);
          Path[x][y] = 1;
     }
}
 

int total, id;
 

void fill(int unit, int i)
{
     int j;
     for (j=0;j<N; j++) if (Path[i][j])
          fill(unit+Value[j], j);
     if (unit> total) {
          total = unit;
          id = i;
     }
}
 

void solveCase()
{
     int max, j,index;
     total = id = 0;
     while (1) {
          total += Value[id];
          max = 0;
          for(j=0; j<N; j++) {
              if(Path[id][j] && Value[j] > max) {
                   max = Value[j];
                   index = j;
              }
          }
          if(!max)
              break;
          id = index;
     }
}
 

void printCase()
{
     printf("Case%d: %d %d\n", Case, total, id);
}
 

int main()
{
     scanf("%d",&T);
     for(Case=1; Case<=T; Case++) {
          readCase();
          solveCase();
          printCase();
     }
     return 0;
}
