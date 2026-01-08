char* largestOddNumber(char* num) {
    int n = strlen(num), index = -1;
    for (int i = n - 1; i > -1; i--) if ((num[i] - '0') % 2 == 1) { index = i; break; }
    if (index == -1) { num[0] = '\0'; return num; }
    num[index + 1] = '\0';
    return num;
}
