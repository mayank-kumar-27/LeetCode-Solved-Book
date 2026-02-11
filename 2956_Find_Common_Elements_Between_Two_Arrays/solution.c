/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int c1 = 0, c2 = 0;
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < nums1Size; i++) for (int j = 0; j < nums2Size; j++)
    if (nums1[i] == nums2[j]) { c1++; break; }
    for (int i = 0; i < nums2Size; i++) for (int j = 0; j < nums1Size; j++)
    if (nums2[i] == nums1[j]) { c2++; break; }

    *returnSize = 2;
    result[0] = c1;
    result[1] = c2;
    return result;
}