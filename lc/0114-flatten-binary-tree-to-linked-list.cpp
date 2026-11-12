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
private:
    TreeNode** helper(TreeNode* root) {
        if (!root) {
            TreeNode** t = new TreeNode*[2];
            t[0] = t[1] = NULL;
            return t;
        }
        TreeNode** l = helper(root->left);
        TreeNode** r = helper(root->right);
        if (!l[0] && !r[0]) {
            TreeNode** t = new TreeNode*[2];
            t[0] = t[1] = root;
            return t;
        }
        if (!l[0]) {
            TreeNode** t = new TreeNode*[2];
            t[0] = root;
            t[1] = r[1];
            return t;
        }
        if (!r[0]) {
            root->right = l[0];
            root->left = NULL;
            TreeNode** t = new TreeNode*[2];
            t[0] = root;
            t[1] = l[1];
            return t;
        }
        TreeNode** t = new TreeNode*[2];
        t[0] = root;
        t[1] = r[1];
        root->right = l[0];
        l[1]->right = r[0];
        root->left = NULL;
        return t;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};