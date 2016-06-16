/*
 * 216.c
 *
 *  Created on: Jun 16, 2016
 *      Author: shohag
 */
#include <stdio.h>
#include <math.h>

#define SIZE 9
int noOfComputers;
int xArray[SIZE], yArray[SIZE];

int square(int x){
    return x * x;
}


int abs216(int number){
    if(number < 0)
        return number * -1;
    else
        return number;
}
int power(int number){
    return number * number;
}
double squareRoot(int number){
    double squareRoot = number / 2;
    double g1;
    do{
        g1 = squareRoot;
        squareRoot = (g1 + (number/g1))/2;
    }
    while((g1-squareRoot) != 0);
    return squareRoot;
}
double calculateDistance(int x1, int x2, int y1, int y2){
    return squareRoot(power(abs216(x1 - x2)) + power(abs216(y1-y2)));
}

int main(){
    printf("216\n");
    double a = pow(8, 2);
    printf("%f", calculateDistance(8, 8, 16, 11));

    return 0;
}
