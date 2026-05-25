bool canReach(char* s, int minJump, int maxJump) {
    int n = strlen(s);
    int* f = (int*)calloc(n, sizeof(int));
    int* p = (int*)malloc(n * sizeof(int));
    f[0] = 1;
    for (int i = 0; i < minJump; i++) p[i] = 1;
    for (int i = minJump; i < n; i++) {
        int l = i - maxJump, r = i - minJump;
        if (s[i] == '0') {
            int t = p[r];
            if (l > 0) t -= p[l - 1];
            f[i] = t != 0 ? 1 : 0;
        }
        p[i] = p[i - 1] + f[i];
    }
    bool r = (f[n - 1] == 1);
    free(f);
    free(p);
    return r;
}
