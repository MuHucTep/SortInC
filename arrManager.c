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

// Алгоритм простейшей сортировки

int* stupidSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return arr;
    }

    int tmp;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i+1]) {
        tmp = arr[i+1]; arr[i+1] = arr[i]; arr[i] = tmp;
        i = -1;
        }
    }

    return arr;
}

// Идея алгоритма обменной сортировки

int* bubbleSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return arr;
    }

    bool needRepeat = true;
    int tmp;

    while (needRepeat) {
        needRepeat = false;
        for (size_t i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i+1]; arr[i+1] = arr[i]; arr[i] = tmp;
                needRepeat = true;
            }
        }

    }

    return arr;
}

// Идея алгоритма упорядочения вставками

int* insertionSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return arr;
    }

    for (size_t i = 1; i < size; i++) {
        int key = arr[i];
        size_t j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
    return arr;
}

// Идея алгоритма упорядочения выбором

int* selectionSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return arr;
    }

    size_t maxIndex = 0;
    size_t sortedPartIndex = size - 1;

    for (int i = 0; sortedPartIndex > 0; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }

        if (i == (int)sortedPartIndex) {
            int tmp = arr[sortedPartIndex]; arr[sortedPartIndex] = arr[maxIndex]; arr[maxIndex] = tmp;
            sortedPartIndex--;
            maxIndex = 0;
            i = -1;
        }
    }

    return arr;
}
