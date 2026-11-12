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
  int sum;
  void preorder(TreeNode* n, int x) {
    if (!n) return;
    x = x * 10 + n->val;
    if (!n->left && !n->right) sum += x;
    else {
      preorder(n->left, x);
      preorder(n->right, x);
    }
  }
  int sumNumbers(TreeNode* root) {
    sum = 0;
    preorder(root, 0);
    return sum;
  }
};