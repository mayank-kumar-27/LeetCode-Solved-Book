int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
char* triangleType(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), comp);
    if (nums[0] + nums[1] <= nums[2]) {
        return "none";
    } else if (nums[0] == nums[1] && nums[1] == nums[2]) {
        return "equilateral";
    } else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
        return "scalene";
    } else {
        return "isosceles";
    }
}