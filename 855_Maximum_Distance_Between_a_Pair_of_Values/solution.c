int maxDistance(int* nums1, int n1s, int* nums2, int n2s) {
    int i = 0, j = 0, a = 0;
    while (i < n1s && j < n2s) {
        if (nums1[i] <= nums2[j]) {
            a = (a > j - i) ? a : j - i;
            j++;
        } else {
            i++;
            if (i > j) j = i;
        }
    }
    return a;
}
