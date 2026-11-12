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
  int maxDepth, res;
  void inorder(TreeNode* n, int depth) {
    if (!n) return;
    //goes to left depths first and 
    inorder(n->left, depth + 1);
    //picks out the max depth's first occurence node (leftmost) then all others for (same depth) will
    //be towards the right and 
    //if a new max depth exists even below this then going to left child first will pick up that depth
    //and store in maxDepth (+updating res) and that will be new leftmost deepest node since got into
    //depth WITH TRAVERSING THE LEFTEST NODE FIRST as next same depth nodes will not be picked into
    //res since will have same depth (so res not updated) and only the leftmost kept !!
    if (depth > maxDepth) {
      maxDepth = depth;
      res = n->val;
    }
    inorder(n->right, depth + 1);
  }
  int findBottomLeftValue(TreeNode* n) {
    maxDepth = -1;
    inorder(n, 0);
    return res;
  }
};