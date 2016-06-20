//Solution 3: (Run Time: 0.0042s)
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
int Depth[SIZE];
int used[SIZE];
void initDepth() {
    int i;
    for (i = 1; i <= N; i++)
        Depth[i] = 0;
}
void initUsed() {
    int i;
    for (i = 1; i <= N; i++)
        used[i] = 0;
}
int stack[SIZE];
int top;
void initStack() {
    top = 0;
}
void push(int n) {
    stack[top] = n;
    used[n] = 1;
    top++;
}
int pop() {
    top--;
    used[stack[top]] = 0;
    return stack[top];
}
int fill(int i) {
    int count = 0;
    while (!Depth[i]) {
        push(i);
        Depth[i] = ++count;
        i = Next[i];
    }
    return i;
}
void findDepth() {
    int i, j, cycleLen, pos;
    for (i = 1; i <= N; i++)
        if (!Depth[i]) {
            j = fill(i);
            cycleLen = Depth[j];
            if (used[j]) {
                cycleLen = Depth[stack[top - 1]] - Depth[j] + 1;
                do {
                    Depth[pop()] = cycleLen;
                } while (stack[top] != j);
            }
            for (pos = 1; top; pos++)
                Depth[pop()] = pos + cycleLen;
        }
}
int index;
void findMax() {
    int i, max;
    max = -1;
    for (i = 1; i <= N; i++) {
        if (Depth[i] > max) {
            max = Depth[i];
            index = i;
        }
    }
}
void solveCase() {
    initDepth();
    initUsed();
    initStack();
    findDepth();
    findMax();
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
