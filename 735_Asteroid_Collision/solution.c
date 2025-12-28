/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* result = malloc(asteroidsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];
        bool destroyed = false;
        while (top >= 0 && result[top] > 0 && current < 0) {
            if (result[top] < abs(current)) top--;
            else if (result[top] == abs(current)) {
                top--;
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }
        if (!destroyed) result[++top] = current;
    }
    *returnSize = top + 1;
    return result;
}
