int smallestNumber(int n) {
    int power = 2;
    while (power <= n) power *= 2;
    return power - 1;
}