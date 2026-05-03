bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal)) return false;

    char* doubled = (char*)malloc((2 * strlen(s) + 1) * sizeof(char));
    strcpy(doubled, s); strcat(doubled, s);
    bool result = (strstr(doubled, goal) != NULL);

    free(doubled);
    return result;
}
