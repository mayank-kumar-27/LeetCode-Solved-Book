class Solution {
    int p = 0, c = 0, m = 0;
    List<Integer> a = new ArrayList<>();
    public int[] findMode(TreeNode r) {
        f(r);
        int[] x = new int[a.size()];
        for (int i = 0; i < x.length; i++) x[i] = a.get(i);
        return x;
    }
    void f(TreeNode r) {
        if (r == null) return;
        f(r.left);
        if (r.val == p) c++;
        else { p = r.val; c = 1; }
        if (c > m) { m = c; a.clear(); a.add(r.val); }
        else if (c == m) { a.add(r.val); }
        f(r.right);
    }
}