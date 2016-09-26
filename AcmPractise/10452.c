//
//  10452.c
//  10276
//
//  Created by Nazia Afroz on 9/26/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#define SIZE 8
char input[SIZE][SIZE];
int m, n;
int hashIndex;
char output[SIZE][SIZE];
char order[SIZE];

void init(){
    
    order[1] = 'I';
    order[2] = 'E';
    order[3] = 'H';
    order[4] = 'O';
    order[5] = 'V';
    order[6] = 'A';
    order[7] = '#';
}

void findHash(){
    int i;
    for (i = 0; i < n; i++)
        if(input[m - 1][i] == '@')
            hashIndex = i;
    
}

void solve(int level, int x, int y){
    if(level == 8){
        return;
    }
    /*left*/
    if(y > 0 && input[x][y - 1] == order[level]){
        solve(level + 1, x, y);
    }
    
}

int main(){
    freopen("/Users/naziaafroz/Desktop/10276/10276/10276.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        int i;
        for(i = 0; i < m; i++)
            scanf("%s", input[i]);
        findHash();
        
    }
    return 0;
}
