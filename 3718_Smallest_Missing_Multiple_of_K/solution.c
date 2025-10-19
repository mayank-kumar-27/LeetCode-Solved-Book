int missingMultiple(int* nums, int numsSize, int k) {
    int n = k;
    while (1) {
        int found = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == k) {
                found = 1;
                break;
            }
        }
        if (!found) return k;
        k += n;
    }
}