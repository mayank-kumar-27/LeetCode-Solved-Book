int minOperations(char* s) {
    int n = strlen(s), c = 0;
    for (int i = 0; i < n; i++) c += (s[i] - '0') != i % 2;
    return c < n - c ? c : n - c;
}