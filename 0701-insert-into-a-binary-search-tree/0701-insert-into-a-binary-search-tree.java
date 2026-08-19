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
    public TreeNode insertIntoBST(TreeNode r, int v) {
        if (r == null) return new TreeNode(v);
        if (v < r.val) r.left = insertIntoBST(r.left, v);
        else r.right = insertIntoBST(r.right, v);
        return r;
    }
}