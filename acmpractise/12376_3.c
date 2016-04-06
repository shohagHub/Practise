//Solution 3: O(N) (Run Time: 0.026)
#include<stdio.h>
 

#define SIZE 101
 

int T;
int N, M;
int Case;
int Value[SIZE];
int Next[SIZE];
 

void initNext()
{
     int i;
     for (i=0;i<N; i++)
          Next[i] = -1;
}
 

void readCase()
{
     int i;
     int x, y;
     scanf("%d%d", &N, &M);
     initNext();
     for (i=0;i<N; i++)
          scanf("%d",&Value[i]);
     for (i=0;i<M; i++) {
          scanf("%d%d", &x, &y);
          if(Next[x] == -1)
              Next[x] = y;
          else if (Value[y] > Value[Next[x]])
              Next[x] = y;
     }
}
 

int total, id;
 

void solveCase()
{
     int max,index, i;
     total = id = 0;
     while(Next[id] != -1) {
          total += Value[Next[id]];
          id = Next[id];
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
