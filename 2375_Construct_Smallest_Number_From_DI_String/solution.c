char* reverse(char* result, int start, int end) {
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    return result;
}
char* smallestNumber(char* pattern) {
    int n = strlen(pattern);
    char* result = malloc(n + 2);

    for (int i = 0; i <= n; i++) result[i] = '0' + (i + 1);
    result[n + 1] = '\0';

    for (int i = 0; i < n; i++) {
        if (pattern[i] == 'D') {
            int start = i;
            while (i < n && pattern[i] == 'D') i++;
            int end = i;
            reverse(result, start, end);
        }
    }
    return result;
}
