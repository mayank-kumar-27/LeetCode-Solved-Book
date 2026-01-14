int myAtoi(char* s) {
    long long result = 0;
    int sign = 1;
    while (*s == ' ') { s++; }

    if (*s == '+' || *s == '-') { if (*s == '-') sign = -1; s++; }

    while (isdigit((unsigned char)*s)) {
        int digit = *s - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) { return (sign == 1) ? INT_MAX : INT_MIN; }
        result = result * 10 + digit;
        s++;
    }
    return (int)(sign * result);
}
