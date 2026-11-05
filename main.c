#include <stdio.h>

#include "mylib.h"

int main() {
    size_t count = 1000;
    int *arr = createRandArr(count, -100, 100);

    InsertionSortASC(arr, count);

    for (size_t i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSTATUS: %d", isSortedArr(arr, count));
}