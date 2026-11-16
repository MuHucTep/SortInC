#include <stdio.h>
#include <time.h>
#include <string.h>
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

void wrappedMergeSort(int *arr, size_t size) {
    mergeSortASC(arr, 0, size - 1);
}

void (*mergeSortIndex)(int *, size_t) = wrappedMergeSort;

typedef void (*SortFunc)(int *arr, size_t size);

int main() {
    srand(time(NULL));

    const SortFunc sortFuncs[] = {
        stupidSortASC,
        bubbleSortASC,
        insertionSortASC,
        selectionSortASC,
        wrappedMergeSort
    };

    const char *funcNames[] = {
        "Stupid sort",
        "Bubble sort",
        "Insertion sort",
        "Selection sort",
        "Merge sort"
    };

    const size_t funcsCount = sizeof(sortFuncs) / sizeof(sortFuncs[0]);

    size_t n;
    int min, max;

    printf("Enter count of elements in array:\n");
    if (scanf("%zu", &n) != 1) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter the minimum possible number for number generation in array:\n");
    if (scanf("%d", &min) != 1) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter the maximum possible number for number generation in array:\n");
    if (scanf("%d", &max) != 1) {
        printf("Input error!\n");
        return 1;
    }

    if (min > max) {
        printf("Error: the minimum number is greater than maximum number.\n");
        return 1;
    }

    size_t selected[32];
    size_t selectedCount = 0;
    size_t num;

    printf("Select functions separated by spaces:\n");
    for (size_t i = 0; i < funcsCount; i++) {
        printf("%zu. %s\n", i + 1, funcNames[i]);
    }
    while (selectedCount <= funcsCount && scanf("%zu", &num) == 1) {
        if (num >= 1 && num <= funcsCount) {
            selected[selectedCount++] = num - 1;
        } else {
            printf("Warning: function %zu does not exist (skipped)\n", num);
        }

        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
    }

    if (selectedCount == 0) {
        printf("No valid functions selected.\n");
        return 1;
    }

    printf("\nCount of elements: %zu\nRange: from %d to %d\n\n", n, min, max);

    int *original = createRandArr(n, min, max);
    if (original == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (size_t i = 0; i < selectedCount; ++i) {
        size_t idx = selected[i];

        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation error!\n");
            free(original);
            return 1;
        }
        memcpy(arr, original, n * sizeof(int));

        double t = MEASURE_TIME(sortFuncs[idx](arr, n));
        bool sorted = isSortedArr(arr, n);

        printf("%s\n", funcNames[idx]);
        printf("Status: %s\n", sorted ? "OK (sorted)" : "FAILED");
        printf("Duration: %.6f sec.\n\n", t);

        free(arr);
    }

    free(original);
    return 0;
}