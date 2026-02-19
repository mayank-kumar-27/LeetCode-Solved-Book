int countBinarySubstrings(char* s) {
    int result = 0, prev = 0, curr = 1;
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) curr++;
        else { prev = curr; curr = 1; }
        if (curr <= prev) result++;
    }   return result;
}