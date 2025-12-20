int minDeletionSize(char** strs, int strsSize) {
    int len = strlen(strs[0]), count = 0;

    for (int col = 0; col < len; col++) {
        for (int row = 0; row < strsSize - 1; row++) {
            if (strs[row][col] > strs[row + 1][col]) {
                count++;
                break;
            }
        }
    }
    return count;
}
