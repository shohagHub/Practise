//Solution 2: (Run Time: TLE)
#include<stdio.h>
#define SIZE 50001
int T;
int N;
int Next[SIZE];
int Case;
void readCase() {
    int i, u, v;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d%d", &u, &v);
        Next[u] = v;
    }
}
int Freq[SIZE];
int used[SIZE];
void initFreq() {
    int i;
    for (i = 1; i <= N; i++)
        Freq[i] = 0;
}
void updateFreq(int i, int n) {
    for (; i <= N; i++)
        if (!Freq[i] && used[i])
            Freq[i] = n;
}
void resetUsed() {
    int i;
    for (i = 1; i <= N; i++)
        used[i] = 0;
}
int countNext(int n) {
    int count = 0;
    while (!used[n]) {
        used[n] = 1;
        count++;
        n = Next[n];
    }
    return count;
}
int index;
void solveCase() {
    int i, max;
    initFreq();
    max = index = 0;
    for (i = 1; i <= N; i++)
        if (!Freq[i]) {
            resetUsed();
            Freq[i] = countNext(i);
            updateFreq(i + 1, Freq[i]);
            if (Freq[i] > max) {
                max = Freq[i];
                index = i;
            }
        }
    /*for (i=1;i<=N; i++) if (Freq[i] > max) {
     max = Freq[i];
     index = i;
     }*/
}
void printCase() {
    printf("Case%d: %d\n", Case, index);
}
int main() {
    scanf("%d", &T);
    for (Case = 1; Case <= T; Case++) {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
