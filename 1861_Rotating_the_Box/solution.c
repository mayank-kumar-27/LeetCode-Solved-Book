/**
 * Return an array of arrays of size *rs.
 * The sizes of the arrays are returned as *rcs array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
char** rotateTheBox(char** b, int m, int* bn, int* rs, int** rcs) {
    int n = bn[0];
    char** r = (char**)malloc(n * sizeof(char*));
    *rs = n;
    *rcs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { r[i] = (char*)malloc(m * sizeof(char)); (*rcs)[i] = m; }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) r[i][j] = b[j][i];

    for (int i = 0; i < n; i++) {
        int l = 0, h = m - 1;
        while (l < h) {
            char temp = r[i][l];
            r[i][l] = r[i][h];
            r[i][h] = temp;
            l++; h--;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (r[i][j] == '.') {
                int rw = -1;
                for (int k = i - 1; k >= 0; k--) {
                    if (r[k][j] == '*') break;
                    if (r[k][j] == '#') { rw = k; break; }
                }
                if (rw != -1) { r[rw][j] = '.'; r[i][j] = '#'; }
            }
        }
    }
    return r;
}
