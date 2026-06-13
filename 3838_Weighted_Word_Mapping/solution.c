char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char* r = (char*)malloc((wordsSize + 1) * sizeof(char));
    for (int i = 0; i < wordsSize; i++) {
        int s = 0;
        for (char* p = words[i]; *p; p++) s += weights[*p - 'a'];
        r[i] = 'z' - s % 26;
    }
    r[wordsSize] = '\0';
    return r;
}