/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int a = 0;
    int getDepth(TreeNode r) {
        if (r == null) return 0;
        int l = getDepth(r.left), q = getDepth(r.right);
        a = Math.max(a, l + q);
        return 1 + Math.max(l, q);
    }
    public int diameterOfBinaryTree(TreeNode r) {
        getDepth(r);
        return a;
    }
}