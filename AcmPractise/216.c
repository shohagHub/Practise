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
int xArray216[SIZE], yArray216[SIZE];
int visited216[SIZE];
double maximum216;
int output216[SIZE], finalOutput[SIZE];
double distanceArray[SIZE], finalDistance[SIZE];


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

void solve216(int level, int lastIndex, double distance){
	if (level == noOfComputers) {
		if (distance < maximum216){
			maximum216 = distance;
			int i;
			for (i = 0; i < noOfComputers; i++) {
				finalOutput[i] = output216[i];
			}
			for (i = 1; i < noOfComputers; i++) {
				finalDistance[i] = distanceArray[i];
			}
		}
		
		return;
	}
	
	int i;
	for (i = 0; i < noOfComputers; i++) {
		if (!visited216[i]) {
			visited216[i] = 1;
			double curretntDistance = 0;
			if (level != 0){
				curretntDistance = calculateDistance(xArray216[i], xArray216[lastIndex], yArray216[i], yArray216[lastIndex]) + 16.0;

				distanceArray[level] = curretntDistance;
			}
			output216[level] = i;
			solve216(level + 1, i, curretntDistance + distance);
			visited216[i] = 0;
		}
	}
}

int main(){
	/*freopen("/Users/enam/Desktop/Shohag_Vai_Desktop/projects/ACM/ACM/216.txt", "r", stdin);*/
	int count = 0;
	while (scanf("%d", &noOfComputers) && noOfComputers) {
		
		count++;
		int i;
		for (i = 0; i < 58; i++) {
			printf("*");
		}
		printf("\n");
		for (i = 0; i < noOfComputers; i++) {
			scanf("%d%d", &xArray216[i], &yArray216[i]);
		}
		maximum216 = 64000;
		solve216(0, -1, 0);
		printf("Network #%d\n", count);
		for (i = 0; i < noOfComputers - 1; i++) {
			
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", xArray216[finalOutput[i]], yArray216[finalOutput[i]], xArray216[finalOutput[i + 1]], yArray216[finalOutput[i + 1]], finalDistance[i + 1]);
		}
		printf("Number of feet of cable required is %.2f.\n", maximum216);
	}
	

	
	
	return 0;
}