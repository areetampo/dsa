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
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int lvl = -1;
    while (!q.empty()) {
      ++lvl;
      int prev = (lvl % 2) ? INT_MAX : INT_MIN;
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode* front = q.front(); q.pop();
        int x = front->val;//val
        // cout << x << " ";
        if (lvl % 2) {
          if (prev <= x || x % 2) return 0;
        } else if (prev >= x || x % 2 == 0) return 0;
        prev = x;
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
      }
      // cout << endl;
    }
    return 1;
  }
};