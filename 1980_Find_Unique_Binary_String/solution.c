char* findDifferentBinaryString(char** nums, int numsSize) {
    char* result = malloc(numsSize + 1);
    for (int i = 0; i < numsSize; i++) result[i] = nums[i][i] == '0' ? '1' : '0';
    result[numsSize] = '\0';
    return result;
}