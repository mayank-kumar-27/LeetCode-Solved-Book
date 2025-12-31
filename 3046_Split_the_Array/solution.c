bool isPossibleToSplit(int* nums, int numsSize) {
    int freq[101] = {0};
    for (int i = 0; i < numsSize; i++) freq[nums[i]]++;
    for (int i = 0; i < 101; i++) if (freq[i] > 2) return false;
    return true;
}
