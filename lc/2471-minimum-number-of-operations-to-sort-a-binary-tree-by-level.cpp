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
    int minimumOperations(TreeNode* ro) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(ro);
        while (!q.empty()) {
            vector<pair<int, int>> v(q.size());
            for (int i = 0; i < v.size(); i++) {
                auto r = q.front(); q.pop();
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
                v[i] = {r->val, i};
            }
            sort(v.begin(), v.end());
            // for (auto &i : v) cout << i.second << " "; cout << "\n";
            for (int i = 0; i < v.size(); i++) {
                while (i != v[i].second) {
                    //i is curr idx
                    int el_at_i = v[i].second,
                        el_at_this_el_idx = v[el_at_i].second;
                    //if not = then swap so el goes to its correct index
                    //and el at that index comes at i:
                    //if = -> while loop over
                    //else != -> for loop moves to next i 
                    swap(v[i].second, v[v[i].second].second);
                    res++;
                }
            }
        }
        return res;
    }
};