int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int result = 0;
    for (int i = 0; i < neededTimeSize - 1; i++) {
        if (colors[i] == colors[i + 1]) {
            int j = i;
            int max_time = neededTime[i];
            int sum_time = neededTime[i];

            while (j + 1 < neededTimeSize && colors[j] == colors[j + 1]) {
                j++;
                sum_time += neededTime[j];
                if (neededTime[j] > max_time) {
                    max_time = neededTime[j];
                }
            }

            result += sum_time - max_time;
            i = j;
        }
    }

    return result;
}