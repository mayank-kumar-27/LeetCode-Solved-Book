bool isPalindrome(char* sub, int len) {
    for (int i = 0; i < len / 2; i++) if (sub[i] != sub[len - 1 - i]) return false;
    return true;
}
char* longestPalindrome(char* s) {
    int n = strlen(s), max_len = 1, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            if (isPalindrome(s + i, len)) {
                if (len > max_len) { max_len = len; start = i; }
            }
        }
    }

    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return result;
}