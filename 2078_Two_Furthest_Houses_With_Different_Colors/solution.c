int maxDistance(int* arr, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (arr[i] != arr[j] && j - i > m) m = j - i;
    return m;
}
