int comp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int max(int a, int b) { return a > b ? a : b; }
long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), comp);
    long long max_happiness = 0;
    for (int i = 0; i < k; i++) {
        max_happiness += max(0, happiness[i] - i);
    }
    return max_happiness;
}
