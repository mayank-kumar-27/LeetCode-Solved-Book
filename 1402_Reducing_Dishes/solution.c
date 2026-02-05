int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int res = 0, sum = 0;
    for (int i = satisfactionSize - 1; i >= 0; i--) {
        sum += satisfaction[i];
        if (sum <= 0) break;
        res += sum;
    }
    return res;
}