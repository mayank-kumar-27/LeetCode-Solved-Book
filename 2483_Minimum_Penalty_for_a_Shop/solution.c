int bestClosingTime(char* customers) {
    int penalty = 0, min_penalty = 0, best_hour = 0;
    for (int i = 0; customers[i] != '\0'; i++) if (customers[i] == 'Y') penalty++;

    min_penalty = penalty;
    for (int i = 0; customers[i] != '\0'; i++) {
        customers[i] == 'Y' ? penalty-- : penalty++;
        if (penalty < min_penalty) min_penalty = penalty, best_hour = i + 1;
    }
    return best_hour;
}
