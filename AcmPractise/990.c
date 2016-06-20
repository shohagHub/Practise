#include <stdio.h>
int capacity;
int constant;
int noOfTreasures;
int depth[100];
int quantity[100];
int tree[1001];
int path[100];
int maximumTreasure;
int recoveredTreasure;
int flag;
void printAnswer(){
	int i;
	if(flag == 0){
		flag = 1;
	}else{
		printf("\n");
	}
	
	printf("%d\n", maximumTreasure);
	for (i = 0; i < noOfTreasures; i++) {
		if (path[i] == 1) {
			recoveredTreasure++;
		}
	}
	printf("%d\n", recoveredTreasure);
	for (i = 0; i < noOfTreasures; i++) {
		if (path[i] == 1) {
			printf("%d %d\n", depth[i], quantity[i]);
		}
	}
	
}


void solve990(int level, int capacity){
	if (level == noOfTreasures) {
		int i;
		int currentTreasure = 0;
		for (i = 0; i < noOfTreasures; i++) {
			if (tree[i] == 1) {
				currentTreasure += quantity[i];
			}
		}
		if (currentTreasure > maximumTreasure) {
			maximumTreasure = currentTreasure;
			for (i = 0; i < noOfTreasures; i++) {
				path[i] = tree[i];
			}
		}
		return;
	}
	
	tree[level] = 0;
	solve990(level + 1, capacity);
	int deductedCapacity = (3 * constant * depth[level]);
	
	if (capacity >= deductedCapacity) {
		tree[level] = 1;
		solve990(level + 1, capacity - (3 * constant * depth[level]));
	}
	
}

//int main(){
//	FILE *fp = freopen("/Users/enam/Desktop/Shohag_Vai_Desktop/projects/ACM/ACM/990.txt", "r", stdin);
//	
//	while (scanf("%d%d", &capacity, &constant) == 2) {
//		scanf("%d", &noOfTreasures);
//		int i;
//		for (i = 0; i < noOfTreasures; i++) {
//			scanf("%d%d", &depth[i], &quantity[i]);
//		}
//		maximumTreasure = 0;
//		recoveredTreasure = 0;
//		solve990(0, capacity);
//		printAnswer();
//	}
//	
//	fclose(fp);
//	return 0;
//}