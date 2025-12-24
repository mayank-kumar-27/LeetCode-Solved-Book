int comp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int total_apples = 0;
    for (int i = 0; i < appleSize; i++) total_apples += apple[i];
    qsort(capacity, capacitySize, sizeof(int), comp);

    int current_capacity = 0;
    for (int i = 1; i < capacitySize + 1; i++) {
        current_capacity += capacity[i - 1];
        if (current_capacity >= total_apples) return i;
    }
    return 0;
}
