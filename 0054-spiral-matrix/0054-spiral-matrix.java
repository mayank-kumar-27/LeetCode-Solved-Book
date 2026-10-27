class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        ArrayList<Integer> a = new ArrayList<>();
        int t = 0, b = m - 1, l = 0, r = n - 1;
        while (t <= b && l <= r) {
            for (int i = l; i <= r; i++) a.add(mat[t][i]); t++;
            for (int i = t; i <= b; i++) a.add(mat[i][r]); r--;
            if (t <= b) { for (int i = r; i >= l; i--) a.add(mat[b][i]); b--; }
            if (l <= r) { for (int i = b; i >= t; i--) a.add(mat[i][l]); l++; }
        } return a;
    }
}