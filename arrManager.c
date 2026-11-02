#include <stdlib.h>
#include <stdbool.h>

// Проверка: отсортирован ли по возрастанию?

bool isSortedArr(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return true;
    }

    for (size_t i = 0; i < size-1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
