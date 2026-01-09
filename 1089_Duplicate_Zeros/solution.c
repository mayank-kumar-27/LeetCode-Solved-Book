void duplicateZeros(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0 && i + 1 < arrSize) {
            for (int j = arrSize - 1; j > i; j--) arr[j] = arr[j - 1];
            arr[i + 1] = 0;
            i++;
        }
    }
}
