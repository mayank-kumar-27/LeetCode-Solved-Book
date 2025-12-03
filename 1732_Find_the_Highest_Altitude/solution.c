// int largestAltitude(int* gain, int gainSize) {
//     int* result = calloc((gainSize + 1), sizeof(int));
//     for (int i = 0; i < gainSize; i++) result[i + 1] = result[i] + gain[i];
//     int max = result[0];
//     for (int i = 0; i < gainSize + 1; i++) if (result[i] > max) max = result[i];
//     return max;
// }

int largestAltitude(int* gain, int gainSize) {
    int temp = 0, max = 0;
    for (int i = 0; i < gainSize; i++) {
        temp += gain[i];
        if (temp > max) max = temp;
    }
    return max;
}