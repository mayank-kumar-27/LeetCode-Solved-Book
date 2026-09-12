import java.util.*;

class Solution {
    public int[] maximumWeight(List<List<Integer>> a) {
        int n = a.size();
        int[][] b = new int[n][4];

        for (int i = 0; i < n; i++) {
            b[i][0] = a.get(i).get(0);
            b[i][1] = a.get(i).get(1);
            b[i][2] = a.get(i).get(2);
            b[i][3] = i;
        }

        Arrays.sort(b, (x, y) -> Integer.compare(x[1], y[1]));

        long[][] d = new long[n + 1][5];
        List<Integer>[][] s = new List[n + 1][5];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 5; j++)
                s[i][j] = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int l = b[i][0], w = b[i][2], id = b[i][3];
            int k = bs(b, i, l);

            for (int j = 1; j < 5; j++) {
                long x = d[i][j];
                long y = d[k][j - 1] + w;

                if (x > y) {
                    d[i + 1][j] = x;
                    s[i + 1][j] = new ArrayList<>(s[i][j]);
                    continue;
                }

                List<Integer> q = new ArrayList<>(s[k][j - 1]);
                q.add(id);
                Collections.sort(q);

                if (x == y && cmp(s[i][j], q) < 0)
                    q = new ArrayList<>(s[i][j]);

                d[i + 1][j] = y;
                s[i + 1][j] = q;
            }
        }

        List<Integer> r = s[n][4];
        int[] z = new int[r.size()];

        for (int i = 0; i < r.size(); i++)
            z[i] = r.get(i);

        return z;
    }

    private int bs(int[][] a, int e, int t) {
        int l = 0, r = e;

        while (l < r) {
            int m = (l + r) >>> 1;

            if (a[m][1] < t) l = m + 1;
            else r = m;
        }

        return l;
    }

    private int cmp(List<Integer> a, List<Integer> b) {
        int n = Math.min(a.size(), b.size());

        for (int i = 0; i < n; i++)
            if (!a.get(i).equals(b.get(i)))
                return Integer.compare(a.get(i), b.get(i));

        return Integer.compare(a.size(), b.size());
    }
}