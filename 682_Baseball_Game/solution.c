int calPoints(char** operations, int operationsSize) {
    int ops[operationsSize], index = 0, sum = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == '+') {
            ops[index] = ops[index - 1] + ops[index - 2];
        } else if (operations[i][0] == 'D') {
            ops[index] = ops[index - 1] * 2;
        } else if (operations[i][0] == 'C') {
            index--;
        } else {
            ops[index] = atoi(operations[i]);
        }
        if (operations[i][0] != 'C') {
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        sum += ops[i];
    }

    return sum;
}