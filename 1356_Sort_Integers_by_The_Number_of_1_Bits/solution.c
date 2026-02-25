/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* x, const void* y) {
    int a = *(int*)x, b = *(int*)y;
    int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
    return ca != cb ? ca - cb : a - b;
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}