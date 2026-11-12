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
    int dfs(TreeNode* ro, unordered_set<int>& s, unordered_map<int, map<int, int>>& m, unordered_map<int, pair<int, int>>& n, int depth) {
        if (!ro) return 0;
        s.insert(ro->val);
        int left_ht = dfs(ro->left, s, m, n, depth + 1),
            right_ht = dfs(ro->right, s, m, n, depth + 1);
        int ht = max(left_ht, right_ht);
        m[depth][ht]++;
        n[ro->val] = {depth, ht};
        return 1 + ht;
    }
    vector<int> treeQueries(TreeNode* ro, vector<int>& q) {
        unordered_set<int> left, right;
        unordered_map<int, map<int, int>> m;
        unordered_map<int, pair<int, int>> n;
        int left_ht = dfs(ro->left, left, m, n, 1),
            right_ht = dfs(ro->right, right, m, n, 1);
        // for (auto &i : n) cout << i.first << " (" << i.second.first << "," << i.second.second << ")\n";
        int orig_ht = max(left_ht, right_ht);
        // cout << "left_ht:" << left_ht << ",right_ht:" << right_ht << ",orig_ht:" << orig_ht << "|\n";
        for (int i = 0; i < q.size(); i++) {
            int del = q[i];
            auto [depth, ht] = n[del];
            // cout << "del:" << del << ",depth:" << depth << ",ht:" << ht << "\n";
            if (depth + ht < orig_ht) {
                // cout << "dep + ht < orig_ht\n";
                q[i] = orig_ht;
            }
            else if (depth + ht == orig_ht) {
                // cout << "depth + ht == orig_ht\ntake same depth with max ht excluding curr deleted node OR depth - 1\n";
                // cout << "distinct heights at curr depth:" << m[depth].size() << ",total nodes with curr depth and max ht:" << m[depth].rbegin()->second << "\n";
                q[i] = m[depth].size() == 1 && m[depth].rbegin()->second == 1 ?
                    depth - 1 : 
                    depth + (m[depth].rbegin()->second > 1 ?
                    m[depth].rbegin()->first : (++m[depth].rbegin())->first);
            }
            // cout << "...\n";
        }
        return q;
    }
};