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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        --depth;
        if (depth == 0) {
            TreeNode* r = new TreeNode(val);
            r->left = root;
            return r;
        }
        if (!root) return nullptr;
        if (depth == 1) {
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = root->left; r->right = root->right;
            root->left = l; root->right = r;
            return root;
        }
        addOneRow(root->left, val, depth);
        addOneRow(root->right, val, depth);
        return root;
    }
};