#include <stdio.h>

#include "mylib.h"

int main() {
    size_t count = 20;
    int *arr = createRandArr(count, -10, 10);

    stupidSortASC(arr, count);
    
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
}