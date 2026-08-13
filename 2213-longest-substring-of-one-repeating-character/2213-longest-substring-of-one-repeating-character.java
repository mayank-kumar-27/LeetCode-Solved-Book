class Solution {
    int[] pre, suf, best;
    char[] s;

    void build(int p, int l, int r) {
        if (l == r) {
            pre[p] = suf[p] = best[p] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m + 1, r);
        merge(p, l, r);
    }

    void merge(int p, int l, int r) {
        int m = (l + r) / 2, a = 2 * p, b = a + 1;

        best[p] = Math.max(best[a], best[b]);
        pre[p] = pre[a];
        suf[p] = suf[b];

        if (s[m] == s[m + 1]) {
            best[p] = Math.max(best[p], suf[a] + pre[b]);
            if (pre[a] == m - l + 1) pre[p] += pre[b];
            if (suf[b] == r - m) suf[p] += suf[a];
        }
    }

    void update(int p, int l, int r, int i) {
        if (l == r) {
            pre[p] = suf[p] = best[p] = 1;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) update(2 * p, l, m, i);
        else update(2 * p + 1, m + 1, r, i);
        merge(p, l, r);
    }

    public int[] longestRepeating(String str, String queryCharacters, int[] queryIndices) {
        s = str.toCharArray();
        int n = s.length, k = queryIndices.length;

        pre = new int[4 * n];
        suf = new int[4 * n];
        best = new int[4 * n];

        build(1, 0, n - 1);

        int[] ans = new int[k];

        for (int i = 0; i < k; i++) {
            s[queryIndices[i]] = queryCharacters.charAt(i);
            update(1, 0, n - 1, queryIndices[i]);
            ans[i] = best[1];
        }

        return ans;
    }
}