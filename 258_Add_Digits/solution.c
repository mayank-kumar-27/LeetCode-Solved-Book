// int add_digits(int num) {
//     int digit = 0, sum = 0;
//     while (num > 0) {
//         digit = num % 10;
//         sum += digit;
//         num /= 10;
//     }
//     return sum;
// }

// int addDigits(int num) {
//     int sum = add_digits(num);
//     while (sum > 9) {
//         sum = add_digits(sum);
//     }
//     return sum;
// }

int addDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + (num - 1) % 9;
}