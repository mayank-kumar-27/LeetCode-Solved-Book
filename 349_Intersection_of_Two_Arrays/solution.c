/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool search(int* arr, int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] > target) return search(arr, low, mid - 1, target);
        else return search(arr, mid + 1, high, target);
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    int index = 0;
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);
    for (int i = 0; i < nums1Size; i++) {
        if (i > 0 && nums1[i] == nums1[i - 1]) continue;
        if (search(nums2, 0, nums2Size - 1, nums1[i])) result[index++] = nums1[i];
    }
    *returnSize = index;
    return result;
}