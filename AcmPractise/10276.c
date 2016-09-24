//
//  10276.c
//  10276
//
//  Created by Nazia Afroz on 9/24/16.
//  Copyright © 2016 Nazia Afroz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define SIZE 2501
int output[SIZE];
int used[SIZE];
int noOfPegs;
int limit;


void reset(){
	int i;
	for(i = 0; i < SIZE; i++){
		used[i] = 0;
		output[i] = 0;
	}
}

void coutAns(){
	int i;
	for(i = 1; used[i]; i++);

	printf("%d\n", i - 1);
}

int isSquare(int n){
    int h = n & 0xF;
    if (h > 9)
        return 0;

    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}


void print(){
    int i;
    for(i = 1; output[i]; i++){
        printf("%d ", output[i]);
        output[i] = 0;
    }

    printf("\n");
}


int solve2(){
	if(noOfPegs == 1){
		used[1] = 1;
		return 1;
	}
	int index = 1;
	int i;
	int first = 1;
	for(i = 1; i < noOfPegs * noOfPegs && index <= limit; i++){

		if(!used[i] && first == 1){
			first = 0;
			used[i] = 1;
			output[index++] = i;
		}
		else if(!used[i] && output[index - 1] && isSquare(output[index - 1] + i)){
			used[i] = 1;
			output[index++] = i;
		}
	}
	if(index - 1 < limit)
		limit = index - 1;

	return index - 1;
}

int main(int argc, const char *argv[]){
    /*freopen("10272.txt", "r", stdin);*/
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    while (T--) {
    	reset();
        scanf("%d", &noOfPegs);
        limit = noOfPegs;
        int i;
        for(i = 0; i < noOfPegs; i++){
        	solve2();
        }
        coutAns();

    }
    return 0;
}
