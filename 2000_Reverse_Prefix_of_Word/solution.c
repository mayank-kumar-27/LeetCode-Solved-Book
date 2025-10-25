char* reversePrefix(char* word, char ch) {
    int index = 0, found = 0;
    while (word[index] != '\0') {
        if (word[index] == ch) {
            found = 1;
            index++;
            break;
        }
        index++;
    }

    if (!found) return word;

    for (int i = 0; i < index / 2; i++) {
        char temp = word[i];
        word[i] = word[index - 1 - i];
        word[index - 1 - i] = temp;
    }

    return word;
}