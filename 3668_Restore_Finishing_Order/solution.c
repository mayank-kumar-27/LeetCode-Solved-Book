/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    int* result = (int*)malloc(orderSize * sizeof(int));
    *returnSize = 0;

    bool friendsSet[101] = {false};
    for (int i = 0; i < friendsSize; i++) {
        friendsSet[friends[i]] = true;
    }

    for (int i = 0; i < orderSize; i++) {
        if (friendsSet[order[i]]) {
            result[(*returnSize)++] = order[i];
        }
    }

    return result;
}