bool canConstruct(char* ransomNote, char* magazine) {
    if (strlen(ransomNote) > strlen(magazine)) return false;

    int counts[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) counts[magazine[i] - 'a']++;

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = ransomNote[i] - 'a';
        if (counts[index] == 0) return false;
        counts[index]--;
    }

    return true;
}