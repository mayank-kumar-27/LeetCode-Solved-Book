bool isOneBitCharacter(int* bits, int bitsSize) {
    for (int i = 0; i < bitsSize; i++) {
        if (i == bitsSize - 1) return true;
        if (bits[i] == 1) i++;
    }
    return false;
}