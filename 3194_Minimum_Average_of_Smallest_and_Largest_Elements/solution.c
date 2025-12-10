int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

double min(double* arr, int n) {
    double minimum = arr[0];
    for (int i = 0; i < n; i++) if (arr[i] < minimum) minimum = arr[i];
    return minimum;
}

double minimumAverage(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    double* averages = malloc(numsSize / 2 * sizeof(double));
    for (int i = 0; i < numsSize / 2; i++) averages[i] = (double)(nums[i] + nums[numsSize - 1 - i]) / 2;
    return min(averages, numsSize / 2);
}