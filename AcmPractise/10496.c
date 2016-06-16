/*
 * 10496.c
 *
 *  Created on: Jun 11, 2016
 *      Author: shohag
 */

#include <stdio.h>
#define SIZE 31
int noOfScenario;
int xSize, ySize;
int startX, startY;
int noOfBeepers;
int bepperXArray[SIZE];
int bepperYArray[SIZE];
int visited10496[SIZE];
int maximun, currentIndex;
int abs(int number){
    if(number < 1)
        return number * (-1);
    return number;
}

void solve10496(int level, int distance){
    if(level == noOfBeepers){
        distance = distance + (abs(bepperXArray[level - 1] - startX) + abs(bepperYArray[level - 1] -startY));
        if(distance < maximun)
            maximun = distance;
        return;
    }



    int i;
    for(i = 0; i < noOfBeepers; i++){
        if(!visited10496[i]){
            visited10496[i] = 1;
            if(level == 0)
                distance = distance + (abs(bepperXArray[i] - startX) + abs(bepperYArray[i] -startY));


            else
                distance = distance + (abs(bepperXArray[i] - bepperXArray[currentIndex]) + abs(bepperYArray[i] -
                        bepperYArray[currentIndex]));
            currentIndex = i;
            solve10496(level + 1, distance);
            visited10496[i] = 0;


        }
    }
}

//int main(){
//    freopen("10496.txt", "r", stdin);
//    printf("10496\n");
//    scanf("%d", &noOfScenario);
//    while(noOfScenario--){
//        scanf("%d%d", &xSize, &ySize);
//        scanf("%d%d", &startX, &startY);
//        scanf("%d", &noOfBeepers);
//        int i;
//        for(i = 0; i < noOfBeepers; i++)
//            scanf("%d %d", &bepperXArray[i], &bepperYArray[i]);
//        maximun = 64000;
//        solve10496(0, 0);
//        printf("The shortest path has length %d", maximun);
//    }
//    return 0;
//}
