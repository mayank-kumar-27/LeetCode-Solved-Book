int maxOperations(char* s) {
    int n = strlen(s);
    int ones = 0;
    int operations = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        } else if (s[i] == '0' && i > 0 && s[i - 1] == '1') {
            operations += ones;
        }
    }

    return operations;
}