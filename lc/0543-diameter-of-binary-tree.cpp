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
  int res;
  int ht(TreeNode* n) {
    if (!n) return 0;
    int l = ht(n->left); 
    int r = ht(n->right);
    res = max(res, l + r);
    return 1 + max(l, r);
  }
  int diameterOfBinaryTree(TreeNode* n) {
    res = 0;
    ht(n);
    return res;
  }
};