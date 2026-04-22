double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int merged_array[nums1Size + nums2Size], i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            merged_array[k++] = nums1[i++];
        } else {
            merged_array[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        merged_array[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        merged_array[k++] = nums2[j++];
    }

    if (k % 2 == 0) {
        return (merged_array[k / 2 - 1] + merged_array[k / 2]) / 2.0;
    } else {
        return merged_array[k / 2];
    }
    return 0;
}
