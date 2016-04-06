//Solution 2: O(N*N/2) (Run Time: 0.026)
#include<stdio.h>
 

#define SIZE 101
 

int T;
int N, M;
int Case;
int Value[SIZE];
int Path[SIZE][SIZE];
int Len[SIZE];
 

void initLen()
{
     int i, j;
     for (i=0;i<N; i++)
          Len[i] = 0;
}
 

void readCase()
{
     int i;
     int x, y;
     scanf("%d%d", &N, &M);
     initLen();
     for (i=0;i<N; i++)
          scanf("%d",&Value[i]);
     for (i=0;i<M; i++) {
          scanf("%d%d", &x, &y);
          Path[x][Len[x]++] = y;
     }
}
 

int total, id;
 

void solveCase()
{
     int max,index, i;
     total = id = 0;
     while (1) {
          total += Value[id];
          max = 0;
          for(i=0; i<Len[id]; i++) {
              if(Value[Path[id][i]] > max) {
                   max = Value[Path[id][i]];
                   index = Path[id][i];
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
