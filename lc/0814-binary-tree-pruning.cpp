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
    TreeNode* pruneTree(TreeNode* n) {
        if (!n) return n;
        TreeNode* l = pruneTree(n->left);
        TreeNode* r = pruneTree(n->right);
        n->left = l; n->right = r;
        if (!l && !r && !n->val) return nullptr;
        //else means the subtree below has a 1
        return n;
    }
};