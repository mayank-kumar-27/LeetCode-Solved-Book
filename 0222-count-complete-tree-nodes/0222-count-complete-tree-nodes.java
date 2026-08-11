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
    public int countNodes(TreeNode r) {
        if (r == null) return 0;
        int l = 0, h = 0;
        TreeNode a = r, b = r;
        while (a != null) {
            l++; a = a.left;
        }
        while (b != null) {
            h++; b = b.right;
        }
        if (l == h) return (1 << l) - 1;
        return 1 + countNodes(r.left) + countNodes(r.right);
    }
}