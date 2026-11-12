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
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({ root, 0 }); //node, its width
    int depth = 0;
    map<int, vector<multiset<int>>> mp;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
        auto p = q.front(); q.pop();
        auto node = p.first; int width = p.second;
        while (mp [width].size() < depth + 1) {
            mp [width].push_back(multiset<int>());
        }
        //mp[width] is the vector of nodes top to bottom (vertical)
        //mp[width][depth] is the nodes at same width and same depth stored in multiset (sorted)
        mp [width][depth].insert(node->val);
        if (node->left) q.push({ node->left, width - 1 });
        if (node->right) q.push({ node->right, width + 1 });
        }
        depth++;
    }
    vector<vector<int>> res;
    for (auto i : mp) {
        res.push_back(vector<int>()); //for next width (column)
        auto vertical = i.second; //nodes in same column [note that the nodes were added with queue traversal of tree in vector so they are top to bottom]
        // dbg(i.first); dbg(vertical.size());
        for (auto nodesAtSameDepth : vertical) { //each multiset<int>
        // dbg(nodesAtSameDepth);
        for (auto nodeVal : nodesAtSameDepth) {
            res [res.size() - 1].push_back(nodeVal);
            // dbg(nodeVal);
        }
        }
        // small_line();
    }
    // dbg(res);
    return res;
  }
};