/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int* result = (int*)calloc(n, sizeof(int));

    int balls = 0, ops = 0;
    for (int i = 0; i < n; i++) {
        result[i] += ops;
        balls += (boxes[i] == '1');
        ops += balls;
    }

    balls = ops = 0;
    for (int i = n - 1; i >= 0; i--) {
        result[i] += ops;
        balls += (boxes[i] == '1');
        ops += balls;
    }

    *returnSize = n;
    return result;
}
