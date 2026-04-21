/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* arr, int n, int* rs) {
    int* r = (int*)malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; i++) { r[i] = arr[i]; r[n + i] = arr[i]; }
    *rs = 2 * n;
    return r;
}
