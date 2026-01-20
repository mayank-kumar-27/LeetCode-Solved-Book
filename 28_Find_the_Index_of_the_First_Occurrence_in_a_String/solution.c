int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') return 0;

    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] != '\0' && haystack[i + j] == needle[j]) j++;
        if (needle[j] == '\0') return i;
    }
    return -1;
}
