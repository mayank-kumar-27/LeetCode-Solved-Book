// long long reverse(int n) {
//     long long num = 0;
//     while (n != 0) {
//         long long digit = n % 10;
//         num = num * 10 + digit;
//         n /= 10;
//     }
//     return num;
// }

// long long sumAndMultiply(int n) {
//     long long num = 0, sum = 0;
//     while (n != 0) {
//         long long digit = n % 10;
//         if (digit != 0) {
//             num = num * 10 + digit;
//             sum += digit;
//         }
//         n /= 10;
//     }
//     return reverse(num) * sum;
// }

long long sumAndMultiply(int n) {
    long long num = 0, sum = 0, multiplier = 1;
    while (n != 0) {
        long long digit = n % 10;
        if (digit != 0) {
            num = digit * multiplier + num;
            multiplier *= 10;
            sum += digit;
        }
        n /= 10;
    }
    return num * sum;
}