class Solution {
    int c = 0;
    Pair<Integer, Integer> f(TreeNode r) {
        if (r == null)
            return new Pair<>(0, 0);
        Pair<Integer, Integer> l = f(r.left);
        Pair<Integer, Integer> q = f(r.right);
        int s = l.getKey() + q.getKey() + r.val;
        int n = l.getValue() + q.getValue() + 1;
        if (r.val == s / n) c++;
        return new Pair<>(s, n);
    }
    public int averageOfSubtree(TreeNode r) {
        f(r);
        return c;
    }
}