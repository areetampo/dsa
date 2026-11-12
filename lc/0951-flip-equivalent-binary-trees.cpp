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
    bool flipEquiv(TreeNode* a, TreeNode* b) {
        // if (!a && !b) return 1;//both null
        // if (a && !b || !a && b) return 0;//anyone null
        if (a == nullptr || b == nullptr) return a == b;
        return a->val == b->val && (flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right) || flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left));
    }
};