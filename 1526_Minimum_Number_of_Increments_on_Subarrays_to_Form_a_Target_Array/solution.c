int minNumberOperations(int* target, int targetSize) {
    int operation = target[0];
    for (int i = 0; i < targetSize - 1; i++) {
        if (target[i + 1] > target[i]) {
            operation += target[i + 1] - target[i];
        }
    }
    return operation;
}