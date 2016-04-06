//Solution: (Run Time: 0.000s)
#include<stdio.h>
#define SIZE 128
int T;
int Case;
char Names[SIZE];
int Trails[SIZE];
int Stack[SIZE];
int Top;
void initStack() {
    Top = 0;
}
void push(int n) {
    Stack[Top] = n;
    Top++;
}
int pop() {
    Top--;
    returnStack[Top];
}
void readCase() {
    scanf("%s", Names);
}
void initTrails() {
    int i;
    for (i = 'A'; i <= 'Z'; i++)
        Trails[i] = 0;
}
void solveCase() {
    int i;
    initStack();
    initTrails();
    for (i = 0; Names[i]; i++) {
        if (!Top || Stack[Top - 1] != Names[i]) {
            push(Names[i]);
            Trails[Names[i]]++;
        } else {
            pop();
            if (Top)
                Trails[Stack[Top - 1]]++;
        }
    }
    Trails[Names[0]]--;
}
void printCase() {
    int i;
    printf("Case%d\n", Case);
    for (i = 'A'; i <= 'Z'; i++)
        if (Trails[i])
            printf("%c= %d\n", i, Trails[i]);
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