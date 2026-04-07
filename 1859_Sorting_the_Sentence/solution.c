char* sortSentence(char* s) {
    char *r = calloc(1000, 1), *words[10];
    int i = 0, c = 0;
    for (char* t = strtok(s, " "); t; t = strtok(NULL, " ")) {
        int p = t[strlen(t) - 1] - '0';
        t[strlen(t) - 1] = '\0';
        words[p] = t;
        c++;
    }
    for (i = 1; i <= c; i++) {
        strcat(r, words[i]);
        strcat(r, " ");
    }
    r[strlen(r) - 1] = '\0';
    return r;
}
