#include <stdlib.h>
#include <limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(arr[0]), comp);

    int min_diff = INT_MAX, size = 0;
    for (int i = 1; i < arrSize; i++) min_diff = (min_diff > arr[i] - arr[i - 1]) ? arr[i] - arr[i - 1] : min_diff;
    for (int i = 1; i < arrSize; i++) size += (arr[i] - arr[i - 1]) == min_diff ? 1 : 0;

    int** result = (int**)malloc(size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == min_diff) {
            result[index] = (int*)malloc(2 * sizeof(int));
            result[index][0] = arr[i - 1];
            result[index][1] = arr[i];
            (*returnColumnSizes)[index] = 2;
            index++;
        }
    }
    *returnSize = size;
    return result;
}