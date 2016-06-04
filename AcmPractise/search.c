/*
 * search.c
 *
 *  Created on: Apr 26, 2016
 *      Author: shohag
 */


#include "search.h"
void testSearch(){
    int array[9] = {43, 2, 47, 21, 13, 32, 78, 7, 10};
    int result = linearSearch(array, 9, 7);
    printf("%d \n", result);
}
int linearSearch(int array[], int length, int element){
    int i = 0;
    for(; i < length; i++){
        if(array[i] == element)
            return i;
    }
    return -1;
}
