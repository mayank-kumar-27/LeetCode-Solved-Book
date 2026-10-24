class Solution {
    public int countDaysTogether(String a, String b, String c, String d) {
        int[] m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, p = new int[13];
        for (int i = 0; i < 12; i++) p[i + 1] = p[i] + m[i];
        int x = day(a, p), y = day(b, p), z = day(c, p), w = day(d, p);
        return Math.max(0, Math.min(y, w) - Math.max(x, z) + 1);
    }
    int day(String s, int[] p) {
        return p[Integer.parseInt(s.substring(0, 2)) - 1] + Integer.parseInt(s.substring(3));
    }
}