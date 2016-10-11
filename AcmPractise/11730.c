//
//  11730.c
//  11730
//
//  Created by Nazia Afroz on 10/10/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#define SIZE 1002
int S, T;
int Case;
int Ans;
int Prime[SIZE];
int PrimeFactorCount[SIZE];
int PrimeFactor[SIZE][20];

void generatePrimeNO(){
    int i, j;
    Prime[0] = 2;
    int count = 1;
    int p;
    for(i = 3; i <= SIZE; i++){
        p = 1;
        for(j = 2; j <= i/2; j++){
            if(i % j == 0){
                p = 0;
                break;
            }
        }
        if(1 == p)
            Prime[count++] = i;
    }
   /* printf("%d", Prime[2]);*/
}

void primeFactor(){
    int i, j;
    int count;
    for(i = 4; i <= SIZE; i++){
        count = 0;
        for(j = 0; Prime[j] <= i / 2; j++){
            
            if(i % Prime[j] == 0){
                PrimeFactor[i][count] = Prime[j];
                count++;
                
            }
        }
        PrimeFactorCount[i] = count;
    }
   /* printf("%d", PrimeFactorCount[10]);*/
}

void readCase(){
    
}

int Output[SIZE];


void print(int level){
    int i;
    for(i = 0; i < level; i++){
        printf("%d ",Output[level]);
    }
    printf("\n");
}

void solve(int level, int sum){
    int j;
    if(level > Ans)
        return;
    if(sum > T){
        return;
    }
    if(sum == T){
        /*print(level);*/
        if(level < Ans)
            Ans = level;
        return;
    }
    
    for(j = 0; j < PrimeFactorCount[sum]; j++){
        solve(level + 1, sum + PrimeFactor[sum][j]);
    }
    
}

void solveCase(){
    Ans = 999999;
    solve(0, S);
    if(Ans == 999999)
        Ans = -1;
}

void printCase(){
    printf("Case %d: %d\n", Case, Ans);
}


int main(){
   freopen("input.txt", "r", stdin);
    Case = 0;
    generatePrimeNO();
    primeFactor();
    while (2 == scanf("%d%d", &S, &T) && S && T) {
        Case++;
        solveCase();
        printCase();
    }
    return 0;
}