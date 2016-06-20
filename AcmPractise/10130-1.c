#include <stdio.h>

int testcase;
int noOfObjects;
int price[1001];
int weight[1001];
int noOfPeople;
int capacityArray[101];
int used10130[1001][101];

void resetUsed(){
	int i, j;
	for (i = 0; i < 1001; i++) {
		for (j = 0; j < 101; j++) {
			used10130[i][j] = -1;
		}
	}
}

void reset10130(){
	int i;
	for (i = 0; i < 1001; i++) {
		price[i] = 0;
		weight[i] = 0;
	}
	for (i = 0; i < 101; i++) {
		capacityArray[i] = 0;
	}
	resetUsed();
}


int solve10130(int level, int capacity){
	if (used10130[level][capacity] != -1) {
		return used10130[level][capacity];
	}
	if (level == noOfObjects) {
		used10130[level][capacity] = 0;
		return 0;
	}
	int left = solve10130(level + 1, capacity);
	int right;
	if (capacity >= weight[level]) {
		right = price[level] + solve10130(level + 1, capacity - weight[level]);
	}
	else
		right = 0;
	
	if (left > right) {
		used10130[level][capacity] = left;
		return left;
	}
	else{
		used10130[level][capacity] = right;
		return right;
	}
	
}

//int main(){
//	int result;
//	scanf("%d", &testcase);
//	while (testcase--) {
//		reset10130();
//		result = 0;
//		scanf("%d", &noOfObjects);
//		int i;
//		for (i = 0; i < noOfObjects; i++) {
//			scanf("%d%d", &price[i], &weight[i]);
//		}
//		scanf("%d", &noOfPeople);
//		
//		for (i = 0; i < noOfPeople; i++) {
//			scanf("%d", &capacityArray[i]);
//			result += solve10130(0, capacityArray[i]);
//			resetUsed();
//		}
//		printf("%d\n", result);
//	}
//}
