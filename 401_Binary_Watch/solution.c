/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bitCount(int x) {
    int count = 0;
    while (x) { count += x & 1; x >>= 1; }
    return count;
}
char** readBinaryWatch(int turnedOn, int* returnSize) {
    if (turnedOn > 8) { *returnSize = 0; return NULL; }
    char** ans = (char**)malloc(720 * sizeof(char*));
    int index = 0;

    for (int hour = 0; hour < 12; hour++) for (int minute = 0; minute < 60; minute++)
    if (bitCount(hour) + bitCount(minute) == turnedOn) {
        ans[index] = (char*)malloc(6 * sizeof(char));
        sprintf(ans[index], "%d:%02d", hour, minute);
        index++;
    }
    *returnSize = index;
    return ans;
}