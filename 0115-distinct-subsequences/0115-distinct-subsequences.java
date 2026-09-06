class Solution {
    public int numDistinct(String s, String t) {
        int[] d = new int[t.length() + 1];
        d[0] = 1;
        for (char a : s.toCharArray()) for (int j = t.length() - 1; j >= 0; j--)
        if (a == t.charAt(j)) d[j + 1] += d[j];
        return d[t.length()];
    }
}