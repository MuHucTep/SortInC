#ifndef MYLIB_H
#define MYLIB_H

int* createRandArr(size_t size, int randMin, int randMax);
bool isSortedArr(int *arr, size_t size);
int* stupidSortASC(int *arr, size_t size);
int* bubbleSortASC(int *arr, size_t size);
int* insertionSortASC(int *arr, size_t size);

#endif
