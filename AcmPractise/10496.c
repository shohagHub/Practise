/*
 * 10496.c
 *
 *  Created on: Jun 12, 2016
 *      Author: nazia
 */
#include <stdio.h>
#define SIZE 31
int noOfScenario;
int xSize, ySize, startX, startY;
int xArray[SIZE], yArray[SIZE], visited[SIZE];
int noOfBeepers, maximum, currentIndex;
int abs(int number){
	if(number < 0)
		return number * (-1);
	return number;
}
void solve(int level, int distance){
	if(level == noOfBeepers){
		if(distance < maximum)
			maximum = distance;
		return;
	}
	int  i;
	for(i = 0; i < noOfBeepers; i++){
		if(!visited[i]){
			visited[i] = 1;
			if(level == 0)
				distance = abs(startX - xArray[i]) + abs(startY - yArray[i]);

			else
				distance = abs(xArray[i] - xArray[currentIndex]) + abs(yArray[i] - yArray[currentIndex]);
			currentIndex = i;
			solve(level + 1, distance);
			visited[i] = 0;
		}
	}
}
int main(){
	freopen("10496.txt", "r", stdin);
	scanf("%d", &noOfScenario);
	while(noOfScenario--){
		scanf("%d%d", &xSize, &ySize);
		scanf("%d%d", &startX, &startY);
		scanf("%d", &noOfBeepers);
		int i;
		for(i = 0; i < noOfBeepers; i++){
			scanf("%d%d", &xArray[i], &yArray[i]);
		}
	}
	maximum = 60000;
	solve(0, 0);
	printf("The shortest path has length %d", maximum);
	return 0;
}

