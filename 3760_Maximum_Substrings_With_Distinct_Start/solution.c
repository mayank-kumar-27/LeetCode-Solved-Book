int maxDistinct(char* s) {
    bool seen[26] = {false};
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (!seen[index]) {
            seen[index] = true;
            count++;
        }
    }
    return count;
}