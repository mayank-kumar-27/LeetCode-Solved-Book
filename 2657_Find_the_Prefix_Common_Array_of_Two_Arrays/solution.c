/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int n, int* B, int BSize, int* returnSize) {
    int* pca = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int a = 0; a <= i; a++) for (int b = 0; b <= i; b++) if (A[a] == B[b]) { c++; break; }
        pca[i] = c;
    }
    *returnSize = n;
    return pca;
}
