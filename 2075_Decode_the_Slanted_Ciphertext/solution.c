char* decodeCiphertext(char* e, int r) {
    int n = strlen(e);
    if (n == 0 || r == 0) {
        char* out = (char*)malloc(1);
        out[0] = '\0';
        return out;
    }
    int c = n / r, k = 0;
    char* res = (char*)malloc((n + 1) * sizeof(char));
    for (int s = 0; s < c; s++) {
        int i = 0, j = s;
        while (i < r && j < c) {
            res[k++] = e[i * c + j];
            i++; j++;
        }
    }
    res[k] = '\0';
    while (k > 0 && res[k - 1] == ' ') res[--k] = '\0';
    return res;
}