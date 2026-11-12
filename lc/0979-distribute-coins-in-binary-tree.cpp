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
    int postorder(TreeNode* n, int* res) {
        if (!n) return 0;
        int l = postorder(n->left, res);
        int r = postorder(n->right, res);
        //l, r -> -ve means debt in subtree and upper nodes give to the subtree and +ve means subtree giving to parent
        //the dist always abs() of it
        *res += abs(l) + abs(r);
        return n->val + l + r - 1;//-1 cuz one coin to keep for itself
    }
    int distributeCoins(TreeNode* n) {
        int res = 0;
        postorder(n, &res);
        return res;
    }
};