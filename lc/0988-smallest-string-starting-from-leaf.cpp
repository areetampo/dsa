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
    //starting from root of tree so need to send string as param
    string smallestFromLeaf(TreeNode* root, string s = "") {
        s = (char)(97 + root->val) + s;
        return (!root->left && !root->right) ? s :
                // (root->left && root->right) ? 
                // min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s)) :
                // root->left ? smallestFromLeaf(root->left, s) : smallestFromLeaf(root->right, s);

                //shorter:

                min(root->left ? smallestFromLeaf(root->left, s) : "|", 
                    root->right ? smallestFromLeaf(root->right, s) : "|");
                //| highest ascii
    }
};