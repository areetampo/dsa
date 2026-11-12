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
    TreeNode* removeLeafNodes(TreeNode* n, int target) {
        if (!n) return n;
        TreeNode* l = removeLeafNodes(n->left, target);
        TreeNode* r = removeLeafNodes(n->right, target);
        n->left = l; n->right = r;
        if (!l && !r && n->val == target) return nullptr;
        return n;
    }
};