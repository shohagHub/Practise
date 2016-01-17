/*
 * 459.c
 *
 *  Created on: Oct 11, 2015
 *      Author: shohag
 */

#include <stdio.h>
#define SIZE 27
int T, N;
char st[5];
int Graph[SIZE][SIZE];
int visited[SIZE];
int count;


void initCase(){
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            Graph[i][j] = 0;
    for(i = 0; i < N; i++)
        visited[i] = 0;
}

void readCase(){
    int x, y;
//    gets(st);
    scanf("%s", st);

    N = st[0] - 'A' + 1;
    initCase();
    while(1 == scanf("%s", st)){
        if(st[0] == '\0')
            break;
        x = st[0] - 'A';
        y = st[1] - 'A';
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }
}

void dfs(int node){
    int i;
    visited[node] = 1;
    for(i = 0; i < N; i++)
        if(Graph[node][i] && !visited[i])
            dfs(i);
}

void solveCase(){
    int i;
    count = 0;
    for(i = 0; i < N; i++)
        if(!visited[i]){
            count++;
            dfs(i);
        }
}

void printCase(){
    printf("%d\n", count);
    if(T)
        printf("\n");
}

int main(){
    scanf("%d", &T);
    getchar();
    getchar();
    while(T--){
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
