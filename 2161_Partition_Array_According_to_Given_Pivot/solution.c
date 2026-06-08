/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* arr, int n, int p, int* rs) {
    int* lr = (int*)malloc(n * sizeof(int));
    int* eq = (int*)malloc(n * sizeof(int));
    int* gr = (int*)malloc(n * sizeof(int));
    int* r = (int*)malloc(n * sizeof(int));
    *rs = n;
    int l = 0, e = 0, g = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > p) gr[g++] = arr[i];
        else if (arr[i] < p) lr[l++] = arr[i];
        else eq[e++] = arr[i];
    }
    int j = 0, i = 0;
    while (i < l) { r[j++] = lr[i++]; } i = 0;
    while (i < e) { r[j++] = eq[i++]; } i = 0;
    while (i < g) { r[j++] = gr[i++]; }
    free(lr); free(eq); free(gr);
    return r;
}
