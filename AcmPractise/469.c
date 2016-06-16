/*
 * 469.c
 *
 *  Created on: Oct 12, 2015
 *      Author: shohag
 */
#include <stdio.h>

#define SIZE 101
char Graph[SIZE][SIZE];
int Visited[SIZE][SIZE];

int N, T;
int Ans;

void readCase469(){
    N = 0;
    while(gets(Graph[N])){
        if(Graph[N][0] != 'W' && Graph[N][0] != 'L')
            break;
        N++;
    }

}

void resetVisited(){
    Ans = 0;
    int i, j;
    for(i = 0; i < N; i++)
        for(j =  0; j < N; j++)
            Visited[i][j] = 0;
}

void fill469(int x, int y){
    Visited[x][y] = 1;
    Ans++;
    if(x - 1 >= 0 && y - 1 >= 0 && Graph[x - 1][y - 1] == 'W' && !Visited[x - 1][y - 1])
        fill469(x -1, y - 1);
    if(x - 1 >= 0 && Graph[x - 1][y] == 'W' && !Visited[x -1][y])
        fill469(x - 1, y);
    if(x - 1 >= 0 && y + 1 < N && Graph[x - 1][y + 1] == 'W' && !Visited[x - 1][y + 1])
        fill469(x -1, y + 1);
    if(y - 1 >= 0 && Graph[x][y - 1] == 'W' && !Visited[x][y - 1])
        fill469(x, y - 1);
    if(y + 1 < N && Graph[x][y + 1] == 'W' && !Visited[x][y + 1])
        fill469(x, y + 1);
    if(x + 1 < N && y - 1 >= 0 && Graph[x + 1][y - 1] == 'W' && !Visited[x + 1][y - 1])
        fill469(x + 1, y - 1);
    if(x + 1 < N && Graph[x + 1][y] == 'W' && !Visited[x + 1][y])
        fill469(x + 1, y);
    if(x + 1 < N && Graph[x + 1][y + 1] == 'W' && !Visited[x + 1][y + 1])
        fill469(x + 1, y + 1);
}

void solve469(){

    resetVisited();
    int i, x, y;
    i = x = y = 0;
    while(Graph[N][i] != ' '){

        x = x * 10 + Graph[N][i] - '0';
        i++;
    }
    i++;
    while(Graph[N][i] != '\0'){
        y = y * 10 + Graph[N][i] - '0';
        i++;
    }
    x--;
    y--;
    fill469(x, y);
    printf("%d", Ans);

}

void print469(){
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++){
            printf("%d\t", Graph[i][j]);
        }
        printf("\n");
    }

}

//int main(){
//    scanf("%d", &T);
//    getchar();
//    getchar();
//    while(T--){
//        readCase469();
////        print469();
//        solve469();
//    }
//    return 0;
//}
