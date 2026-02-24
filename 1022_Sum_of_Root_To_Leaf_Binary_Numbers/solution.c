/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* node, int curr) {
    if (!node) return 0;
    curr = curr * 2 + node->val;
    if (!node->left && !node->right) return curr;
    return dfs(node->left, curr) + dfs(node->right, curr);
}
int sumRootToLeaf(struct TreeNode* root) { return dfs(root, 0); }