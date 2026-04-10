int minimumDistance(int* nums, int numsSize) {
    int L[200] = {0}, r = 200;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i] - 1, p = i + 1;
        int pk = L[v], o = pk & 255, c = pk >> 8;
        L[v] = c | (p << 8);
        if (o) { int d = (p - o) << 1; if (d < r) r = d; }
    }
    return -(r == 200) | r;
}
