class Solution {
    public int[] lexicographicallySmallestArray(int[] a, int l) {
        int n = a.length;
        int[][] b = new int[n][2];

        for (int i = 0; i < n; i++) {
            b[i][0] = a[i];
            b[i][1] = i;
        }

        java.util.Arrays.sort(b, (x, y) -> Integer.compare(x[0], y[0]));

        for (int i = 0; i < n; ) {
            int j = i + 1;

            while (j < n && (long)b[j][0] - b[j - 1][0] <= l)
                j++;

            int[] id = new int[j - i];
            for (int k = i; k < j; k++)
                id[k - i] = b[k][1];

            java.util.Arrays.sort(id);

            for (int k = i; k < j; k++)
                a[id[k - i]] = b[k][0];

            i = j;
        }

        return a;
    }
}