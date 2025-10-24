int removeDuplicates(int* nums, int numsSize) {
    int index = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            nums[index++] = nums[i];
        }
    }

    nums[index] = nums[numsSize - 1];
    return index + 1; //kyuki size return krna hai
}