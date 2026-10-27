class Solution {
    public String[] createGrid(int m, int n) {
        String[] r = new String[m];
        r[0] = ".".repeat(n);
        String ro = "#".repeat(n - 1) + ".";
        for (int i = 1; i < m; i++) r[i] = ro;
        return r;
    }
}