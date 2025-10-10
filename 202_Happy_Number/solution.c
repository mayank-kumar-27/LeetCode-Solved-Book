int sum_of_squares(int n) {
    int sum = 0, digit = 0;
    while (n > 0) {
        digit = n % 10;
        sum += (digit * digit);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = sum_of_squares(slow);
        fast = sum_of_squares(sum_of_squares(fast));
    } while (slow != fast);
    return slow == 1;
}