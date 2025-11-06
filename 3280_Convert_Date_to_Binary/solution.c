char* convertDateToBinary(char* date) {
    int y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);

    char* result = (char*)malloc(100);
    sprintf(result, "%b-%b-%b", y, m, d);

    return result;
}