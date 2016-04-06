#include<stdio.h>
 

#define SIZE 101
 

int T;
int R, C;
int M, N;
int W;
int isWater[SIZE][SIZE];
int Case;
int Even, Odd;
 

int front, rear;
int X[SIZE*SIZE], Y[SIZE*SIZE];
 

void initQueue()
{
     front = rear = 0;
}
 

int isEmpty()
{
     if (front == rear)
          return 1;
     return 0;
}
 

void push(int x, int y)
{
     X[rear] = x;
     Y[rear] = y;
     rear++;
}
 

void pop(int *x, int *y)
{
     *x = X[front];
     *y = Y[front];
     front++;
}
 

void initWater()
{
     int i, j;
     for (i=0; i<R; i++) for (j=0; j<C; j++)
          isWater[i][j] = 0;
}
 

void readCase()
{
     int i, x, y;
     scanf("%d %d %d %d", &R, &C, &M, &N);
     initWater();
     scanf("%d", &W);
     for (i=0; i<W; i++) {
          scanf("%d %d", &x, &y);
          isWater[x][y] = 1;
     }
}
 

int dx[8], dy[8];
int dxLen;
 

int isValidPosition(int x, int y)
{
     if (x < 0)
          return 0;
     if (y < 0)
          return 0;
     if (x >= R)
          return 0;
     if (y >= C)
          return 0;
     if (isWater[x][y])
          return 0;
     return 1;
}
 

int used[SIZE][SIZE];
int K[SIZE][SIZE];
 

void resetUsed()
{
     int i, j;
     for (i=0; i<R; i++) for (j=0; j<C; j++)
          used[i][j] = 0;
}
 

void resetK()
{
     int i, j;
     for (i=0; i<R; i++) for (j=0; j<C; j++)
          K[i][j] = 0;
}
 

void go(int x, int y)
{
     int i, nx, ny;
     for (i=0; i<dxLen; i++) {
          nx = x + dx[i];
          ny = y + dy[i];
          if (isValidPosition(nx, ny)) {
              K[nx][ny]++;
              if (!used[nx][ny]) {
                   used[nx][ny] = 1;
                   push(nx, ny);
              }
          }
     }
}
 

void printK()
{
     int i, j;
     for (i=0; i<R; i++) {
          for (j=0; j<C; j++)
              printf("%4d", K[i][j]);
          printf("\n");
     }
     printf("\n");
}
 

void initdxdy()
{
     int i, j, k;
     for (i=0; i<8; i++) {
          if (i&4) {
              dx[i] = M;
              dy[i] = N;
          }
          else {
              dx[i] = N;
              dy[i] = M;
          }
          if (i&2)
              dx[i] *= -1;
          if (i&1)
              dy[i] *= -1;
     }
     dxLen = 8;
     for (i=0; i<dxLen; i++) {
          for (j=i+1; j<dxLen; j++) {
              if (dx[i] == dx[j] && dy[i] == dy[j]) {
                   dxLen--;
                   for (k=j; k<dxLen; k++) {
                        dx[k] = dx[k+1];
                        dy[k] = dy[k+1];
                   }
              }
          }
     }
     /*dx[0] = dx[1] = M;
     dx[2] = dx[3] = -M;
     dx[4] = dx[5] = N;
     dx[6] = dx[7] = -N;
 

     dy[0] = dy[2] = N;
     dy[1] = dy[3] = -N;
     dy[4] = dy[6] = M;
     dy[5] = dy[7] = -M;*/
}
 

void traverse()
{
     int x, y;
     initQueue();
     resetUsed();
     resetK();
     push(0, 0);
     used[0][0] = 1;
     initdxdy();
     while (!isEmpty()) {
          pop(&x, &y);
          go(x, y);
     }
}
 

void countSquare()
{
     int i, j;
     Even = Odd = 0;
     for (i=0; i<R; i++) for (j=0; j<C; j++) if (K[i][j] || (!i && !j)){
          if (K[i][j] & 1)
              Odd++;
          else
              Even++;
     }
}
 

void solveCase()
{
     traverse();
     countSquare();
}
 

void printCase()
{
     printf("Case %d: %d %d\n", Case, Even, Odd);
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
