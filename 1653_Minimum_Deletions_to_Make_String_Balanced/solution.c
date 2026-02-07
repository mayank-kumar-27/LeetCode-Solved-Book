int minimumDeletions(char* s) {
    int n = strlen(s), a = 0, b = 0;
    for (int i = 0; i < n; i++) a += (s[i] == 'a');
    int result = n;
    for (int i = 0; i < n; i++) {
        a -= (s[i] == 'a');
        result = (result > a + b) ? a + b : result;
        b += (s[i] == 'b');
    }
    return result;
}