bool kLengthApart(int* nums, int numsSize, int k) {
    int* index = (int*)malloc(numsSize * sizeof(int));
    int indices = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] == 1) index[indices++] = i;
    for (int i = 0; i < indices - 1; i++)
        if (index[i + 1] - index[i] <= k) return false;
        
    return true;
}