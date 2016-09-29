#include <stdio.h>
#define SIZE 8
int T;
int M, N, hashIndex;
char input[SIZE][SIZE];
char order[SIZE];
int output[SIZE];

void reset(){
	int i;
	for(i = 0; i < SIZE; i++)
		output[i] = 0;
}

void initCase(){
	order[0] = '@';
	order[1] = 'I';
	order[2] = 'E';
	order[3] = 'H';
	order[4] = 'O';
	order[5] = 'V';
	order[6] = 'A';
	order[7] = '#';
}

void printCase(){
	int i;

	for(i = 0; i < 7; i++){
/*printf("%d ", output[i]);*/
		if(output[i] == 1)
			printf("left");
		if(output[i] == 2)
			printf("forth");
		if(output[i] == 3)
			printf("right");
		if(i != 6)
			printf(" ");
	}
	printf("\n");
}

void findHash(){
    int i;
    for (i = 0; i < N; i++)
        if(input[M - 1][i] == '@')
            hashIndex = i;

}

void solve(int level, int i, int j){
	if(order[level] != input[i][j])
		return;
	if(order[level] == '#'){
		printCase();
		return;
	}
	if(j > 0){
		output[level] = 1;
		solve(level + 1, i, j - 1);
	}
	if(j < N - 1){
		output[level] = 3;
		solve(level + 1, i, j + 1);
	}
	if(i > 0){
		output[level] = 2;
		solve(level + 1, i - 1, j);
	}
}




void solveCase(){
	solve(0, M - 1, hashIndex);
}


int main(){
	freopen("10452.txt", "r", stdin);
	scanf("%d", &T);
	int i;
	initCase();
	for(i = 0; i < T; i++){
		scanf("%d%d", &M, &N);
		int j;
		for(j = 0; j < M; j++){
			scanf("%s", input[j]);
		}
		findHash();
		solveCase();
	}
	printf("\n");
	return 0;

}
