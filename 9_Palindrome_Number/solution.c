bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revHalf = 0;
    while (x > revHalf) {
        int digit = x % 10;
        revHalf = revHalf * 10 + digit;
        x /= 10;
    }

    return (x == revHalf || x == revHalf / 10);
}
