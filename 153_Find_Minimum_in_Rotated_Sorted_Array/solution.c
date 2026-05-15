int findMin(int* a, int n) {
    int l = 0, h = n - 1;
    while (l < h) {
        int m = l + (h - l) / 2;
        if (a[m] > a[h]) l = m + 1;
        else h = m;
    }
    return a[l];
}
