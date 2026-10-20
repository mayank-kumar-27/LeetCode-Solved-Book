class Solution {
    public int sortableIntegers(int[] a) {
        int n = a.length, s = 0;
        int[] t = a.clone();
        Arrays.sort(t);

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            boolean ok = true;
            for (int i = 0; i < n && ok; i += k) {
                ok = check(a, t, i, k);
            }
            if (ok) s += k;
        }
        return s;
    }

    private boolean check(int[] a, int[] t, int l, int k) {
        int[] p = new int[k];
        for (int i = 1, j = 0; i < k; i++) {
            while (j > 0 && t[l + i] != t[l + j]) j = p[j - 1];
            if (t[l + i] == t[l + j]) j++;
            p[i] = j;
        }
        for (int i = 0, j = 0; i < 2 * k; i++) {
            int v = a[l + (i % k)];
            while (j > 0 && v != t[l + j]) j = p[j - 1];
            if (v == t[l + j]) j++;
            if (j == k) return true;
        }
        return false;
    }
}