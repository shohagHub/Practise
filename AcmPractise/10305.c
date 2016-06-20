#include <stdio.h>

int noOfTasks;
int noOfPrecedence;
int precedenceArray[100][100];
int U[100];
int output[100];
int count;
int flag10305 = 0;



void print10305(){
	if (flag10305) {
		return;
	}
	flag10305 = 1;
	int j;
	for (j = 0; j < noOfTasks; j++) {
		printf("%d", output[j]);
	}
	printf("\n");
}

void solve10305(int level){
	if (level == noOfTasks) {
		print10305();
		return;
	}
	int i;
	for (i = 1; i <= noOfTasks; i++) {
		if (U[i] == 0) {
			int j;
			for (j = 1; j <= noOfTasks; j++) {
				if (precedenceArray[i][j] && U[j]) {
//					printf("precedence[%d][%d]\n", j, i);
					return;
				}
			}
			
			
			U[i] = 1;
			output[level] = i;
			solve10305(level + 1);
			U[i] = 0;
		}
		
	}
	
}

int main(){
	int i;
	FILE *fp = freopen("/Users/enam/Desktop/Shohag_Vai_Desktop/projects/ACM/ACM/10305.txt", "r", stdin);
	while (scanf("%d%d", &noOfTasks, noOfPrecedence) == 2) {
		scanf("%d", &noOfTasks);
		scanf("%d", &noOfPrecedence);
		for (i = 0; i < noOfPrecedence; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			precedenceArray[a][b] = 1;
		}
		scanf("%d%d");
		solve10305(0);
	}
	
	fclose(fp);
	return 0;
}