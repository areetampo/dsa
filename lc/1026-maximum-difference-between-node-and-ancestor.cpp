/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;//base case
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(dfs(node->left, mn, mx), dfs(node->right, mn, mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};