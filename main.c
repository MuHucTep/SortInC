#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "mylib.h"

#define MEASURE_TIME(func_call) \
    ({ \
        clock_t _start = clock(); \
        func_call; \
        clock_t _end = clock(); \
        (double)(_end - _start) / CLOCKS_PER_SEC; \
    })


int main() {
    srand(time(NULL));

    size_t n = 2048;
    int min = -1000;
    int max = 1000;
    printf("Count of elements: %d\nRange: from %d to %d\n\n", n, min, max);
    
    int* arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(stupidSortASC(arr, n));
        bool isSorted = isSortedArrASC(arr, n);
        printf("Stupid sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);

    arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(bubbleSortASC(arr, n));
        bool isSorted = isSortedArrASC(arr, n);
        printf("Bubble sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);

    arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(InsertionSortASC(arr, n));
        bool isSorted = isSortedArrASC(arr, n);
        printf("Insertion sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);

    arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(selectionSortASC(arr, n));
        bool isSorted = isSortedArrASC(arr, n);
        printf("Selection sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);

    arr = createRandArr(n, min, max);

    if (arr != NULL) {
        double t = MEASURE_TIME(mergeSortASC(arr, 0, n - 1));
        bool isSorted = isSortedArrASC(arr, n);
        printf("Merge sort\nStatus: %d\nDuration: %.6f sec.\n\n", isSorted, t);
    }

    free(arr);
    
    return 0;
}