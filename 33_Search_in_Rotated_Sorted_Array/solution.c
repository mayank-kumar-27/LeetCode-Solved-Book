int search(int* arr, int n, int t) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == t) return mid;
        if (arr[l] <= arr[mid]) {
            if (t >= arr[l] && t < arr[mid]) r = mid - 1;
            else l = mid + 1;
        }
        else {
            if (t > arr[mid] && t <= arr[r]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}
