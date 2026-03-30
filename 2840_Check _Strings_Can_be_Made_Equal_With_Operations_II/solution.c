bool checkStrings(char* s1, char* s2) {
    int freq[52] = {0};
    int n = strlen(s1);
    for (int i = 0; i < n; i++) {
        int off = (i % 2 == 1) ? 26 : 0;
        char a = s1[i];
        char b = s2[i];
        freq[a - 'a' + off]++;
        freq[b - 'a' + off]--;
    }
    for (int i = 0; i < 52; i++) if (freq[i] != 0) return false;
    return true;
}