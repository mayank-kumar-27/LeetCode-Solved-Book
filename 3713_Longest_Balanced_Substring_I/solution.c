int longestBalanced(char* s) {
    int n = strlen(s), result = 0;

    for (int i = 0; i < n; i++) {
        int freq[26] = {0};
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            int first = 0, ok = 1;
            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    if (first == 0) first = freq[k];
                    else if (freq[k] != first) { ok = 0; break; }
                }
            }
            if (ok) { int len = j - i + 1; result = (len > result) ? len : result; }
        }
    }
    return result;
}