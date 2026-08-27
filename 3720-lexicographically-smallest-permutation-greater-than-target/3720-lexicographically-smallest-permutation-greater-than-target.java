class Solution {
    public String lexGreaterPermutation(String s, String t) {
        int n = s.length(), c[] = new int[26];
        for (char x : s.toCharArray()) c[x - 'a']++;

        char[] a = t.toCharArray();

        for (int i = 0; i < n; i++) {
            int x = a[i] - 'a';

            if (c[x] > 0) {
                c[x]--;
                continue;
            }

            for (int k = i; k >= 0; k--) {
                if (k < i) c[a[k] - 'a']++;

                for (int j = t.charAt(k) - 'a' + 1; j < 26; j++) {
                    if (c[j] > 0) {
                        a[k] = (char)('a' + j);
                        c[j]--;
                        return new String(a, 0, k + 1) + f(c);
                    }
                }
            }
            return "";
        }

        for (int i = n - 1; i >= 0; i--) {
            c[a[i] - 'a']++;

            for (int j = t.charAt(i) - 'a' + 1; j < 26; j++) {
                if (c[j] > 0) {
                    a[i] = (char)('a' + j);
                    c[j]--;
                    return new String(a, 0, i + 1) + f(c);
                }
            }
        }

        return "";
    }

    String f(int[] c) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < 26; i++)
            while (c[i]-- > 0)
                b.append((char)('a' + i));
        return b.toString();
    }
}