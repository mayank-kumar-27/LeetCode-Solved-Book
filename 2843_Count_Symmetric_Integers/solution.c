int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int i = low; i <= high; i++) {
        char num[12];
        sprintf(num, "%d", i);
        int n = strlen(num);

        if (n % 2 != 0) continue;

        int mid = n / 2;

        int s1 = 0;
        for (int j = 0; j < mid; j++) {
            s1 += num[j] - '0';
        }

        int s2 = 0;
        for (int j = mid; j < n; j++) {
            s2 += num[j] - '0';
        }

        if (s1 == s2) {
            count++;
        }
    }

    return count;
}