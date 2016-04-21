/*
 * Sorting.c
 *
 *  Created on: Apr 20, 2016
 *      Author: shohag
 */

/*
 *
 * Merge Sort:
 * Pseudocode for merge technique
 * Merge(A, L, R)
 * i<-j-<k<-0 , respectively index for L, R and A
 * nL, nR respectively size for L and R array
 * while(i < nL && j < nR){
 *
 *  if(L[i] < R[j]){
 *      A[k] = L[i]; i++;
 *  }
 *  else{
 *      A[K] = R[j]; j++;
 *  }
 *  k++;
 * }
 *
 * while(i < nL){
 *  A[K] = L[i];k++;i++;
 * }
 * while(j < nR){
 *  A[k] = R[j]; j++; k++;
 * }
 *
 *
 *
 *
 *
 * */

#include "Sorting.h"


void testMergeSort(){
    int array[] = {2, 4, 6, 1, 8, 5, 3, 7};
    mergeSort(array, 8);
}

void printArray(int array[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int lArray[], int nL, int rArray[], int nR, int array[]){

    int i, j, k;
    i = j = k = 0;

    while(i < nL && j < nR){
        if(lArray[i] < rArray[j]){
            array[k] = lArray[i];
            i++;
        }
        else{
            array[k] = rArray[j];
            j++;
        }
        k++;
    }

    while(i < nL){
        array[k] = lArray[i];
        i++;
        k++;
    }
    while(j < nR){
        array[k] = rArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int length){
    int mid;
    if(length < 2)
        return;
    mid = length/2;
    int lArray[mid];
    int rArray[length -mid];
    int i;
    for(i = 0; i < mid; i++){
        lArray[i] = array[i];
    }
    for(i = mid; i < length; i++){
        rArray[i - mid] = array[i];
    }
    mergeSort(lArray, mid);
    mergeSort(rArray, length - mid);
    merge(lArray, mid, rArray, length - mid, array);
    printArray(array, length);
}
