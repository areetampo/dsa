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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> m;
        for (auto& i : d) {
            int par = i[0], child = i[1], isLeft = i[2];
            if (m.find(par) == m.end()) m[par] = new TreeNode(par);
            if (m.find(child) == m.end()) m[child] = new TreeNode(child);
            if (isLeft) m[par]->left = m[child];
            else m[par]->right = m[child];
        }
        for (auto& i : d) {//delete children from map
            m.erase(i[1]);
        }
        return m.begin()->second;
    }
};