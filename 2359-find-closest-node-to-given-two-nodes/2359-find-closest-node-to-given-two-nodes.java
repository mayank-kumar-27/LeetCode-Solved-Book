class Solution {
    public int closestMeetingNode(int[] e, int a, int b) {
        int n = e.length;
        int[] x = new int[n], y = new int[n];
        Arrays.fill(x, -1);
        Arrays.fill(y, -1);
        for (int i = a, d = 0; i != -1 && x[i] == -1; i = e[i]) x[i] = d++;
        for (int i = b, d = 0; i != -1 && y[i] == -1; i = e[i]) y[i] = d++;
        int r = -1, m = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (x[i] != -1 && y[i] != -1) {
                int d = Math.max(x[i], y[i]);
                if (d < m) { m = d; r = i; }
            }
        } return r;
    }
}