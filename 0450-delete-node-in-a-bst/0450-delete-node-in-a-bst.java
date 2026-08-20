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
    public TreeNode deleteNode(TreeNode r, int k) {
        if (r == null) return null;
        if (k < r.val) r.left = deleteNode(r.left, k);
        else if (k > r.val) r.right = deleteNode(r.right, k);
        else {
            if (r.left == null) return r.right;
            if (r.right == null) return r.left;
            TreeNode s = r.right;
            while (s.left != null) s = s.left;
            r.val = s.val;
            r.right = deleteNode(r.right, s.val);
        } return r;
    }
}