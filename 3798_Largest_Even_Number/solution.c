char* largestEven(char* s) {
    int n = strlen(s), size = 0;
    for (int i = n - 1; i >= 0; i--) if (s[i] == '2') { size = i + 1; break; }

    char* result = (char*)malloc(size + 1);
    for (int i = 0; i < size; i++) result[i] = s[i];

    result[size] = '\0';
    return result;
}
