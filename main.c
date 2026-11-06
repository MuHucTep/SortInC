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

    printf("Count of elements: %zu\nRange: from %d to %d\n\n", n, min, max);

    for (size_t i = 0; i < 5; i++) {
        int* arr = createRandArr(n, min, max);

        if (arr != NULL) {
            double t = MEASURE_TIME(sortFuncs[i](arr, n));
            bool isSorted = isSortedArr(arr, n);
            printf("Stupid sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
        }

        free(arr);
    }
    
    return 0;
}