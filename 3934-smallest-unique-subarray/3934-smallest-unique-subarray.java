class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;
        int[] sa = new int[n];
        int[] r = new int[n];
        int[] nr = new int[n];
        int[] t = new int[n];

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            r[i] = nums[i];
        }

        int m = 0;
        for (int x : nums) m = Math.max(m, x);

        int[] c = new int[Math.max(n + 1, m + 2)];

        for (int k = 1; k < n; k <<= 1) {
            Arrays.fill(c, 0);
            for (int i : sa) {
                int x = (i + k < n ? r[i + k] : -1) + 1;
                c[x]++;
            }
            for (int i = 1; i <= m + 1; i++) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int x = sa[i];
                int y = (x + k < n ? r[x + k] : -1) + 1;
                t[--c[y]] = x;
            }

            int[] s = sa;
            sa = t;
            t = s;

            Arrays.fill(c, 0);
            for (int i : sa) c[r[i] + 1]++;
            for (int i = 1; i <= m + 1; i++) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int x = sa[i];
                t[--c[r[x] + 1]] = x;
            }

            s = sa;
            sa = t;
            t = s;

            nr[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];
                int x = r[a], y = a + k < n ? r[a + k] : -1;
                int z = r[b], w = b + k < n ? r[b + k] : -1;
                nr[b] = nr[a] + (x != z || y != w ? 1 : 0);
            }

            s = r;
            r = nr;
            nr = s;
            m = r[sa[n - 1]];

            if (m == n - 1) break;
        }

        int[] p = new int[n];
        int[] l = new int[n];

        for (int i = 0; i < n; i++) p[sa[i]] = i;

        int h = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == 0) {
                h = 0;
                continue;
            }

            int j = sa[p[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;

            l[p[i]] = h;
            if (h > 0) h--;
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            int x = i + 1 < n ? l[i + 1] : 0;
            int y = Math.max(l[i], x) + 1;

            if (sa[i] + y - 1 < n) {
                ans = Math.min(ans, y);
            }
        }

        return ans;
    }
}