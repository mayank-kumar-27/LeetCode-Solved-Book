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
    public int sumOfLeftLeaves(TreeNode r) {
        if (r == null) return 0;
        if (r.left != null && r.left.left == null && r.left.right == null) return r.left.val + sumOfLeftLeaves(r.right);
        return sumOfLeftLeaves(r.left) + sumOfLeftLeaves(r.right);
    }
}