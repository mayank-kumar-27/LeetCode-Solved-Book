class Solution {
    public int[] assignTasks(int[] s, int[] t) {
        int n = s.length, m = t.length;
        int[] a = new int[m];
        PriorityQueue<long[]> q = new PriorityQueue<>((x, y) -> 
            x[0] != y[0] ? Long.compare(x[0], y[0]) : Long.compare(x[1], y[1])
        );
        PriorityQueue<long[]> f = new PriorityQueue<>((x, y) -> {
            if (x[0] != y[0]) return Long.compare(x[0], y[0]);
            if (x[1] != y[1]) return Long.compare(x[1], y[1]);
            return Long.compare(x[2], y[2]);
        });
        for (int i = 0; i < n; i++) q.offer(new long[]{s[i], i});
        long tm = 0;
        int i = 0, k = 0;
        while (i < m) {
            if (tm < i) tm = i;
            while (!f.isEmpty() && f.peek()[0] <= tm) {
                long[] v = f.poll();
                q.offer(new long[]{s[(int)v[1]], v[1]});
            }
            if (q.isEmpty()) {
                tm = f.peek()[0];
                continue;
            }
            long[] u = q.poll();
            a[k++] = (int)u[1];
            f.offer(new long[]{tm + t[i], u[1], u[0]});
            i++;
        } return a;
    }
}