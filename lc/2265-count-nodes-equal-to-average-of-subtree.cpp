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
    int r;
    pair<int, int> f(TreeNode* i) { // sum, nodes cnt
        if (!i) return {0, 0};
        auto [ls, lc] = f(i->left);
        auto [rs, rc] = f(i->right);
        int s = i->val + ls + rs, c = 1 + lc + rc;
        r += i->val == s / c;
        return make_pair(s, c);
    }
    int averageOfSubtree(TreeNode* root) {
        r = 0;
        f(root);
        return r;
    }
};