#include<stdio.h>
#define SIZE 26
int N;
char Map[SIZE][SIZE];
int Visited[SIZE][SIZE];
int Image, War;
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
void fill(int x, int y) {
    Visited[x][y] = 1;
    if (x - 1 >= 0 && y - 1 >= 0 && Map[x - 1][y - 1] == '1'
            && !Visited[x - 1][y - 1])
        fill(x - 1, y - 1);
    if (x - 1 >= 0 && Map[x - 1][y] == '1' && !Visited[x - 1][y])
        fill(x - 1, y);
    if (x - 1 >= 0 && y + 1 < N && Map[x - 1][y + 1] == '1'
            && !Visited[x - 1][y + 1])
        fill(x - 1, y + 1);
    if (y - 1 >= 0 && Map[x][y - 1] == '1' && !Visited[x][y - 1])
        fill(x, y - 1);
    if (y + 1 < N && Map[x][y + 1] == '1' && !Visited[x][y + 1])
        fill(x, y + 1);
    if (x + 1 < N && y - 1 >= 0 && Map[x + 1][y - 1] == '1'
            && !Visited[x + 1][y - 1])
        fill(x + 1, y - 1);
    if (x + 1 < N && Map[x + 1][y] == '1' && !Visited[x + 1][y])
        fill(x + 1, y);
    if (x + 1 < N && y + 1 < N && Map[x + 1][y + 1] == '1'
            && !Visited[x + 1][y + 1])
        fill(x + 1, y + 1);
}
void solveCase() {
    int i, j;
    War = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (Map[i][j] == '1' && !Visited[i][j]) {
                War++;
                fill(i, j);
            }
}
void  printCase() {
    printf("Imagenumber %d contains %d war eagles.\n", Image++, War);
}
int main() {
    Image = 1;
    while (1 == scanf("%d", &N)) {
        initCase();
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
