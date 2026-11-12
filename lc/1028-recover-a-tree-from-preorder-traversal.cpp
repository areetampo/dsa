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
  TreeNode* f(string s, int* idx, int* depth, int D) {
    //whenever enters f() always a numeric value at idx
    int val = 0;
    while (*idx < s.length() && s[*idx] != '-') {
      val = val * 10 + (int)(s[*idx] - '0'); 
      ++(*idx);
    }
    TreeNode* n = new TreeNode(val);

    *depth = 0;//for maintaing num of dashes
    while (*idx < s.length() && s[(*idx)] == '-') {++(*depth); ++(*idx);}
    if (*depth == D + 1) {//is the next depth node (firstly the left child)
      n->left = f(s, idx, depth, D + 1);
    } else return n;//sice depth <= D + 1 that means less and curr idx* numeric
                    //value is child of a previous ancestor node
    //returned after building left subtree adn if curr numeric value at depth == D + 1
    if (*depth == D + 1) {//then that is the right child of this node we are at right now
      n->right = f(s, idx, depth, D + 1);
    }
    return n;
  }
  TreeNode* recoverFromPreorder(string s) {    
    int idx = 0, depth = 0;
    return f(s, &idx, &depth, 0);
  }
};