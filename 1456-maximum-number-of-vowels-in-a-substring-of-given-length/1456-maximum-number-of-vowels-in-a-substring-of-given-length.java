class Solution {
    private boolean is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    public int maxVowels(String s, int k) {
        int c = 0, n = s.length();
        for (int i = 0; i < k; i++) if (is_vowel(s.charAt(i))) c++;
        int m = c;
        for (int i = k; i < n; i++) {
            if (is_vowel(s.charAt(i - k))) c--;
            if (is_vowel(s.charAt(i))) c++;
            m = m > c ? m : c;
        } return m;
    }
}