int longestBalanced(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        int evenCount = 0, oddCount = 0, even[numsSize], odd[numsSize];
        for (int j = i; j < numsSize; j++) {
            bool found = false;
            if (nums[j] % 2 == 0) {
                for (int k = 0; k < evenCount; k++) if (even[k] == nums[j]) { found = true; break; }
                if (!found) even[evenCount++] = nums[j];
            } else {
                for (int k = 0; k < oddCount; k++)  if (odd[k] == nums[j]) { found = true; break; }
                if (!found) odd[oddCount++] = nums[j];
            }
            if (evenCount == oddCount) { int length = j - i + 1; if (length > result) result = length; }
        }
    }
    return result;
}
