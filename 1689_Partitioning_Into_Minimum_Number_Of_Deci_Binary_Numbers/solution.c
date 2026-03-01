int minPartitions(char* n) {
    char max = n[0];
    for (int i = 0; n[i] != '\0'; i++) if (n[i] > max) max = n[i];
    return max - '0';
}