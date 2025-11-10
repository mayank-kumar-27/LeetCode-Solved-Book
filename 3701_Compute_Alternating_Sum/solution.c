// int alternatingSum(int* nums, int numsSize) {
//     int result = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (i % 2 == 0) result += nums[i];
//         else result -= nums[i];
//     }
//     return result;
// }

int alternatingSum(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result += (i % 2 == 0) ? nums[i] : -nums[i];
    }
    return result;
}