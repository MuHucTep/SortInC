#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "mylib.h"

#define MEASURE_TIME(func_call) \
    ({ \
        clock_t _start = clock(); \
        func_call; \
        clock_t _end = clock(); \
        (double)(_end - _start) / CLOCKS_PER_SEC; \
    })

int* wrappedMergeSort(int *arr, size_t size) {
    mergeSortASC(arr, 0, size - 1);
}

int* (*mergeSortIndex)(int *, size_t) = wrappedMergeSort;

typedef int* (*SortFunc)(int *arr, size_t size);

int main() {
    srand(time(NULL));

    SortFunc sortFuncs[] = {
        stupidSortASC,
        bubbleSortASC,
        insertionSortASC,
        selectionSortASC,
        wrappedMergeSort
    };

    size_t n;
    int min;
    int max;
    size_t funcNum;

    printf("Enter count of elements in array:\n");
    if (scanf("%zu", &n) != 1) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter the maximum possible number for number generation in array:\n");
    if (scanf("%d", &max) != 1) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter the minimum possible number for number generation in array:\n");
    if (scanf("%d", &min) != 1) {
        printf("Input error!\n");
        return 1;
    }

    if (min > max) {
        printf("Error: the minimum number is greater than maximum number.\n");
        return 1;
    }

    printf("Choose the func:\n1. stupid sort\n2. bubble sort\n3. insertion sort\n4. selection sort\n5. merge sort\n");
    if(scanf("%zu", &funcNum) != 1) {
        if (funcNum > 5 && funcNum < 1) {
            printf("Error: there are only 5 funcs (choose 1, 2, 3, 4 or 5).\n");
            return 1;
        }
        printf("Input error!\n");
        return 1;
    } 

    printf("Count of elements: %zu\nRange: from %d to %d\n\n", n, min, max);

    int* arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(sortFuncs[funcNum](arr, n));
        bool isSorted = isSortedArr(arr, n);
        printf("Stupid sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);
    
    return 0;
}