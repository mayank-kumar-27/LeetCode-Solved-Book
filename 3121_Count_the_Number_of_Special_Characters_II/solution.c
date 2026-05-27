int numberOfSpecialChars(char* word) {
    int l[26], f[26];
    memset(l, -1, sizeof(l));
    memset(f, -1, sizeof(f));
    for (int i = 0; word[i]; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') l[c - 'a'] = i;
        else { if (f[c - 'A'] == -1) f[c - 'A'] = i; }
    }
    int r = 0;
    for (int i = 0; i < 26; i++) if (l[i] != -1 && f[i] != -1 && l[i] < f[i]) r++;
    return r;
}
