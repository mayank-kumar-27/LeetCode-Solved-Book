int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(piles[0]), comp);
    int result = 0;
    for (int i = 0; i < pilesSize / 3; i++) {
        result += piles[pilesSize - (2 * i + 2)];
    }
    return result;
}