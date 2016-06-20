//Solution: DFS, Recursion (Run Time: 0.015s)
#include<stdio.h>
#define SIZE 202
int N;
charMap[SIZE][SIZE];
intVisited[SIZE][SIZE];
int Case, BlackWin;
void initCase() {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            Visited[i][j] = 0;
}
void readCase() {
    int i;
    for (i = 0; i < N; i++)
        scanf("%s", Map[i]);
}
int fill(int x, int y) {
    if (x == N - 1)
        return1;
    Visited[x][y] = 1;
    if (x - 1 >= 0 && y - 1 >= 0 && Map[x - 1][y - 1] == 'b'
            && !Visited[x - 1][y - 1] && fill(x - 1, y - 1))
        return1;
    if (x - 1 >= 0 && Map[x - 1][y] == 'b' && !Visited[x - 1][y]
            && fill(x - 1, y))
        return1;
    if (y - 1 >= 0 && Map[x][y - 1] == 'b' && !Visited[x][y - 1]
            && fill(x, y - 1))
        return1;
    if (y + 1 < N && Map[x][y + 1] == 'b' && !Visited[x][y + 1]
            && fill(x, y + 1))
        return1;
    if (x + 1 < N && Map[x + 1][y] == 'b' && !Visited[x + 1][y]
            && fill(x + 1, y))
        return1;
    if (x + 1 < N && y + 1 < N && Map[x + 1][y + 1] == 'b'
            && !Visited[x + 1][y + 1] && fill(x + 1, y + 1))
        return1;
    return 0;
}
voidsolveCase()
{
    int i;
    BlackWin = 0;
    for (i=0;i<N; i++) if (Map[0][i] == 'b' && !Visited[0][i] && fill(0,i)) {
        BlackWin = 1;
        break;
    }
}
voidprintVisited()
{
    int i, j;
    for (i=0;i<N; i++) {
        for(j=0; j<N; j++)
        printf("%d", Visited[i][j]);
        printf("\n");
    }
}
voidprintCase()
{
    /*printVisited();*/
    printf("%d", Case++);
    if(BlackWin)
    printf("B\n");
    else
    printf("W\n");
}
int main() {
    /*freopen("input.txt","r", stdin);*/
    Case = 1;
    while (1 == scanf("%d", &N)) {
        if (!N)
            break;
        initCase();
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
