int findTheWinner(int n, int k) {
    int *friends = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) friends[i] = i + 1;

    int len = n, index = 0;
    while (len > 1) {
        index = (index + k - 1) % len;         
        for (int i = index; i < len - 1; i++) friends[i] = friends[i + 1];
        len--;
    }

    int winner = friends[0];
    free(friends);
    return winner;
}
