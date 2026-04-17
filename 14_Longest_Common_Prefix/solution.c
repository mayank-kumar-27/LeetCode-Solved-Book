int cmp(const void* a, const void* b) { return strcmp(*(char**)a, *(char**)b); }
char* longestCommonPrefix(char** a, int n) {
    qsort(a, n, sizeof(char*), cmp);
    char *s = a[0], *t = a[n - 1];
    int i = 0;
    while (s[i] && t[i] && s[i] == t[i]) i++;
    char* r = (char*)malloc(i + 1);
    strncpy(r, s, i);
    r[i] = '\0';
    return r;
}
