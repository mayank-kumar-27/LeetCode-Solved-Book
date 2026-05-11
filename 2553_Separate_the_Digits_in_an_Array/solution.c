/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* arr, int ns, int* rs) {
    int td = 0;
    for (int i = 0; i < ns; i++) {
        int x = arr[i];
        if (x == 0) td++;
        else {
            while (x > 0) {
                td++;
                x /= 10;
            }
        }
    }
    int* r = (int*)malloc(td * sizeof(int));
    int idx = 0;
    for (int i = 0; i < ns; i++) {
        int x = arr[i], s = 0;
        int* tmp = (int*)malloc(10 * sizeof(int));
        if (x == 0) {
            r[idx++] = 0;
            continue;
        }
        while (x > 0) {
            tmp[s++] = x % 10;
            x /= 10;
        }
        for (int j = s - 1; j >= 0; j--) r[idx++] = tmp[j];
        free(tmp);
    }
    *rs = td;
    return r;
}
