char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1, j = strlen(b) - 1, carry = 0;
    int k = (i > j ? i : j) + 2;
    char* result = (char*)malloc(k + 1);

    result[k--] = '\0';
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }
    return result + k + 1;
}