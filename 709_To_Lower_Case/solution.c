char* toLowerCase(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    // int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}