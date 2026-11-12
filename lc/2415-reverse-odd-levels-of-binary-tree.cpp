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
    void f(TreeNode* r1, TreeNode* r2, int level) {
        if (!r1 || !r2) return;
        if (level % 2 == 0) swap(r1->val, r2->val);
        f(r1->left, r2->right, level + 1);
        f(r1->right, r2->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* ro) {
        f(ro->left, ro->right, 2);
        return ro;
    }
};