#include<stdio.h>
#define SIZE 27
int T, N;
char st[5];
int Path[SIZE][SIZE];
int Visited[SIZE];
int Count;
void initCase() {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            Path[i][j] = 0;
    for (i = 0; i < N; i++)
        Visited[i] = 0;
}
void readCase() {
    int x, y;
    gets(st);
    N = st[0] - 'A' + 1;
    initCase();
    while (gets(st)) {
        if (st[0] == '\0')
            break;
        x = st[0] - 'A';
        y = st[1] - 'A';
        Path[x][y] = 1;
        Path[y][x] = 1;
    }
}
int fill(int x) {
    int i;
    Visited[x] = 1;
    for (i = 0; i < N; i++)
        if (Path[x][i] && !Visited[i])
            fill(i);
}
void solveCase()
{
    int i;
    Count = 0;
    for (i=0;i<N; i++) if (!Visited[i]) {
        Count++;
        fill(i);
    }
}
void printCase()
{
    printf("%d\n",Count);
    if (T)
    printf("\n");
}
int main() {
    scanf("%d", &T);
    getchar();
    getchar();
    while (T--) {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
