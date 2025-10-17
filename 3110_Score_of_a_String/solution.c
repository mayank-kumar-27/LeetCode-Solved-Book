int scoreOfString(char* s) {
    int n = strlen(s), sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int sum_of_ascii = s[i] - s[i + 1];
        sum += abs(sum_of_ascii);
    }
    return sum;
}