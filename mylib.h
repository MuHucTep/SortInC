#ifndef MYLIB_H
#define MYLIB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int* createRandArr(size_t size, int randMin, int randMax);
bool isSortedArr(int *arr, size_t size);
void stupidSortASC(int *arr, size_t size);
void bubbleSortASC(int *arr, size_t size);
void insertionSortASC(int *arr, size_t size);
void selectionSortASC(int *arr, size_t size);
void mergeSortASC(int arr[], int left, int right);

#endif

<<<<<<< HEAD
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

void stupidSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return;
    }

    int tmp;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i+1]) {
        tmp = arr[i+1]; arr[i+1] = arr[i]; arr[i] = tmp;
        i = -1;
        }
    }
}

// Идея алгоритма обменной сортировки

void bubbleSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return;
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
}

// Идея алгоритма упорядочения вставками

void insertionSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return;
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
}

// Идея алгоритма упорядочения выбором

void selectionSortASC(int *arr, size_t size) {
    if (arr == NULL || size < 2) {
        return;
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
}

// Идея алгоритма упорядочения слиянием

void merge(int arr[], int left, int mid, int right);

void mergeSortASC(int arr[], int left, int right) {
    if (left < right) {
      
        // Нахождение середины 
        int mid = left + (right - left) / 2;

        // Дальнейшее дробление подмассивов
        mergeSortASC(arr, left, mid);
        mergeSortASC(arr, mid + 1, right);

        // Объединение подмассива в сортированный массив
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создание подмассивов
    int leftArr[n1], rightArr[n2];

    // Вставка данных в подмассивы
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Объединение массивов в сортированным порядке
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Вставка оставшихся элементов левого массива, если есть
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Вставка оставшихся элементов левого массива, если есть
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
=======
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

    // * list of funcs
    for (size_t i = 0; i < funcsCount; i++) {
        printf("%zu. %s\n", i + 1, funcNames[i]);
    }

    // * Get funcs list
    while (selectedCount <= funcsCount && scanf("%zu", &num) == 1) {
        if (num >= 1 && num <= funcsCount) {
            selected[selectedCount++] = num - 1;
        } else {
            printf("Warning: function %zu does not exist (skipped)\n", num);
        }

        // * Check end of choosing
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

    // * Creating original array
    int *original = createRandArr(n, min, max);
    if (original == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (size_t i = 0; i < selectedCount; ++i) {
        size_t idx = selected[i];

        // * Memory allocation for copy of orig. array
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation error!\n");
            free(original);
            return 1;
        }
        // * Copy orig. array
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
>>>>>>> main
