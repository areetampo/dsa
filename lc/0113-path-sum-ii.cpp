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
    void dfs(TreeNode* r, int sum, int t, stack<int> &s, vector<vector<int>> &res) {//sum = currSum
        if (!r) return;//dont use sum + r->val > t as there can be -ve vals also and will return before complete dfs
        sum += r->val;
        s.push(r->val);
        if (sum == t && !r->left && !r->right) {
            vector<int> v;
            while (!s.empty()) {v.push_back(s.top()); s.pop();}
            reverse(v.begin(), v.end());
            res.push_back(v);
            for (int &i : v) s.push(i);
            s.pop();
            sum -= r->val;
            return;
        }
        dfs(r->left, sum, t, s, res);
        dfs(r->right, sum, t, s, res);
        s.pop();
        sum -= r->val;
    }
    vector<vector<int>> pathSum(TreeNode* r, int t) {
        vector<vector<int>> res;
        stack<int> s;
        dfs(r, 0, t, s, res);
        return res;
    }
};