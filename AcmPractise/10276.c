//
//  10276.c
//  10276
//
//  Created by Nazia Afroz on 9/24/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define SIZE 51
int output[SIZE];
int used[SIZE];
int noOfPegs;

int isSquare(int n){
    int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
        return 0;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}

void print(){
    int i;
    for(i = 0; output[i]; i++){
        printf("%d ", output[i]);
        output[i] = 0;
    }
    printf("\n");
}

void solve(int level){
    if(level == noOfPegs){
        print();
        return;
    }
    int i;
    for(i = 1; i < noOfPegs * noOfPegs; i++){
        if(level == 0){
            if(!used[i]){
                used[i] = 1;
                output[level] = i;
                solve(level + 1);
            }
                
        }
        else{
            if(!used[i] && output[level - 1] && isSquare(output[level - 1] + i)){
                used[i] = 1;
                output[level] = i;
                solve(level + 1);
            }
        }
    }
    print();
}

int main(int argc, const char *argv[]){
    freopen("/Users/naziaafroz/Desktop/10276/10276/10276.txt", "r", stdin);
    setbuf(stdout, NULL);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &noOfPegs);
//        printf("%d %d\n", noOfPegs, isSquare(noOfPegs));
        solve(0);
    }
    return 0;
}