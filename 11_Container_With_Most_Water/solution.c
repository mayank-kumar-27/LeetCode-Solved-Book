int maxArea(int* height, int heightSize) {
    int result = 0, l = 0, r = heightSize - 1, area;

    while (l < r) {
        area = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
        if (area > result) result = area;
        if (height[l] < height[r]) l++; else r--;
    }
    return result;
}
