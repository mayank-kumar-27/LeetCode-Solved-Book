int numberOfSpecialChars(char* word) {
    int s[128] = {0};
    for (int i = 0; word[i]; i++) s[(unsigned char)word[i]] = 1;
    int r = 0;
    for (char c = 'a'; c <= 'z'; c++) if (s[(int)c] && s[(int)(c - 'a' + 'A')]) r++;
    return r;
}
