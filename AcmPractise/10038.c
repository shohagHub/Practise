#include <stdio.h>

int N;
int A[3001];
int result;
int compare;
void solve10038(int level){
	if (level == N -1) {
		return;
	}
	int a1;
	
	a1 = A[level] - A[level + 1];
	if (a1 < 0) {
		a1 *= -1;
	}
	if (level != 0) {
		
		if (((a1 + 1) == compare) || ((a1 - 1) == compare)) {
			compare = a1;
			solve10038(level + 1);
		}
		else{
			result = 1;
			return;
		}
	}
	else{
		compare = a1;
		solve10038(level + 1);
	}
	
}

//int main(){
//	FILE *fp = freopen("/Users/enam/Desktop/Shohag_Vai_Desktop/projects/ACM/ACM/10038.txt", "r", stdin);
//	while (1== scanf("%d", &N)) {
//		compare = 0;
//		result = 0;
//		int i;
//		for (i = 0; i < N; i++) {
//			scanf("%d", &A[i]);
//		}
//		solve10038(0);
//		if (result == 0) {
//			printf("Jolly\n");
//		}else
//			printf("Not Jolly\n");
//	}
//	fclose(fp);
//	return 0;
//}
