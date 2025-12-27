int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    char* concat1 = (char*)malloc(len1 + len2 + 1);
    char* concat2 = (char*)malloc(len1 + len2 + 1);

    sprintf(concat1, "%s%s", str1, str2);
    sprintf(concat2, "%s%s", str2, str1);

    int match = strcmp(concat1, concat2) == 0;
    free(concat1);
    free(concat2);

    if (!match) {
        char* empty = (char*)malloc(1);
        *empty = '\0';
        return empty;
    }

    int gcd_len = gcd(len1, len2);
    char* result = (char*)malloc(gcd_len + 1);
    strncpy(result, str1, gcd_len);
    result[gcd_len] = '\0';
    return result;
}
