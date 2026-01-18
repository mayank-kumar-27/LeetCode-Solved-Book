bool isvowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; }

char* reverseVowels(char* s) {
    int i = 0, size = 0;
    while (s[i] != '\0') { if (isvowel(s[i])) size++; i++; }
    i = 0;

    char* vowels = (char*)malloc(size * sizeof(char));
    int index = 0;
    while (s[i] != '\0') { if (isvowel(s[i])) vowels[index++] = s[i]; i++; }
    i = 0;

    int n = strlen(s);
    while (s[i] != '\0') { if (isvowel(s[i])) { s[i] = vowels[size - 1]; size--; } i++; }

    free(vowels);
    return s;
}
