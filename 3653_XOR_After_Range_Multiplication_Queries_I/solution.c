#define M 1000000007
int xorAfterQueries(int* a, int n, int** qs, int qn, int* qc) {
    for (int i = 0; i < qn; i++) {
        int l = qs[i][0], r = qs[i][1], k = qs[i][2], v = qs[i][3];
        for (int j = l; j <= r; j += k) {
            long long x = a[j];
            x = (x * v) % M;
            a[j] = (int)x;
        }
    }
    int x = 0;
    for (int i = 0; i < n; i++) x ^= a[i];
    return x;
}
