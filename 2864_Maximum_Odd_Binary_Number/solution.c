// char* maximumOddBinaryNumber(char* s) {
//     int i = -1, n = strlen(s), ones = 0, index = 0;
//     char* result = (char*)calloc(n + 1, sizeof(char));

//     while (s[++i] != '\0') if (s[i] == '1') ones++;
 
//     for (int i = 0; i < ones - 1; i++) result[index++] = '1';
//     for (int i = 0; i < n - ones; i++) result[index++] = '0';
//     result[index++] = '1';
//     result[index] = '\0';
//     return result;
// }

char* maximumOddBinaryNumber(char* s) {
    int n = strlen(s), ones = 0;
    for (int i = 0; i < n; i++) ones += s[i] == '1';

    char* r = calloc(n + 1, 1);
    memset(r, '1', ones - 1);
    memset(r + ones - 1, '0', n - ones);
    r[n - 1] = '1';
    return r;
}