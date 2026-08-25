class Solution {
    public int missingMultiple(int[] a, int k) {
        int n = k;
        while (true) {
            boolean f = false;
            for (int x : a) if (x == k) { f = true; break; }
            if (!f) return k;
            k += n;
        }
    }
}