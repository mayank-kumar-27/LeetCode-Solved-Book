class Solution {
    public int[] validSequence(String s, String t) {
        int n = s.length(), m = t.length();
        int[] a = new int[m];
        Arrays.fill(a, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--)
            if (j >= 0 && s.charAt(i) == t.charAt(j)) a[j--] = i;

        int[] r = new int[m];
        int x = 0; j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s.charAt(i) == t.charAt(j) || (x == 0 && (j == m - 1 || i < a[j + 1]))) {
                if (s.charAt(i) != t.charAt(j)) x = 1;
                r[j++] = i;
            }
        } return j == m ? r : new int[0];
    }
}