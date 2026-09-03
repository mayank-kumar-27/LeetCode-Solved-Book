class Solution {
    public boolean uniformArray(int[] a) {
        Arrays.sort(a);
        return ok(a, 0) || ok(a, 1);
    }

    boolean ok(int[] a, int p) {
        boolean[] s = new boolean[2];
        for (int x : a) {
            int q = x & 1;
            if (q != p && !s[q ^ p]) return false;
            s[q] = true;
        }
        return true;
    }
}