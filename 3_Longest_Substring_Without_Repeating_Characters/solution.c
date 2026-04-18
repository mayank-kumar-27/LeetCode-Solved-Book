int lengthOfLongestSubstring(char* s) {
    int char_set[128] = {0}, left = 0, max_length = 0;
    for (int right = 0; s[right] != '\0'; right++) {
        while (char_set[(unsigned char)s[right]] == 1) { char_set[(unsigned char)s[left]] = 0; left++; }
        char_set[(unsigned char)s[right]] = 1;
        int current_length = right - left + 1;
        if (current_length > max_length) { max_length = current_length; }
    }
    return max_length;
}
