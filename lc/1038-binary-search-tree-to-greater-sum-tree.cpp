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
    int f(TreeNode* n, int s) {
        if (!n) return s;
        int r = f(n->right, s);
        n->val += r;
        int l = f(n->left, n->val);
        return l;
    }
    TreeNode* bstToGst(TreeNode* n) {
        f(n, 0);
        return n;
    }
};