#ifndef MYLIB_H
#define MYLIB_H

#include <stdbool.h>
#include <stdlib.h>

int* createRandArr(size_t size, int randMin, int randMax);
bool isSortedArr(int *arr, size_t size);
void stupidSortASC(int *arr, size_t size);
void bubbleSortASC(int *arr, size_t size);
void insertionSortASC(int *arr, size_t size);
void selectionSortASC(int *arr, size_t size);
void mergeSortASC(int arr[], int left, int right);

#endif
