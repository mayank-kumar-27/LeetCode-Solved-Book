class BIT {
    int n;
    long[] a, b;
    BIT(int n) {
        this.n = n;
        a = new long[n + 2];
        b = new long[n + 2];
    }
    int lb(int i) {
        return i & -i;
    }
    void add(int l, int r, int v) {
        upd(l, v);
        upd(r + 1, -v);
    }
    void upd(int i, int v) {
        i++;
        int j = i;
        while (i <= n) {
            a[i] += v;
            b[i] += (long) j * v;
            i += lb(i);
        }
    }
    long sum(int i) {
        i++;
        long j = i + 1, s = 0;
        i = Math.min(i, n);
        while (i > 0) {
            s += j * a[i] - b[i];
            i -= lb(i);
        } return s;
    }
    long query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
}

class Solution {
    public int sumCounts(int[] a) {
        int n = a.length;
        long ans = 0, cur = 0, mod = 1000000007;
        BIT bit = new BIT(n + 10);
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int j = m.getOrDefault(a[i], -1) + 1;
            long q = bit.query(j, i);
            cur = (cur + 2 * q + i - j + 1) % mod;
            ans = (ans + cur) % mod;
            bit.add(j, i, 1);
            m.put(a[i], i);
        } return (int) ans;
    }
}