class Solution {
    public int coinChange(int[] c, int a) {
        int[] d = new int[a + 1];
        Arrays.fill(d, a + 1);
        d[0] = 0;
        for (int i = 1; i <= a; i++) {
            for (int x : c) {
                if (x <= i) d[i] = Math.min(d[i], d[i - x] + 1);
            }
        } return d[a] > a ? -1 : d[a];
    }
}