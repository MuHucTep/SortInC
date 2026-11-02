#include <stdlib.h>
#include <stdbool.h>

#include "mylib.h"

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

// Создание массива с случайными элементами в указанном диапозоне

int* createRandArr(size_t size, int randMin, int randMax) {
    if (randMin > randMax) {
        return NULL;
    }

    int *arr = (int*) malloc(size *sizeof(int));

    if (arr == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = randMin + rand() % (randMax - randMin + 1);
    }

    return arr;
}
