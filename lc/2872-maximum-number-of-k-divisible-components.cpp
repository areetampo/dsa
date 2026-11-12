class Solution {
public:
    int res = 0;
    long long dfs(int curr, vector<vector<int>>& g, vector<int>& vals, int k, vector<int>& vis) {
        vis[curr] = 1;
        long long subtree_sum = vals[curr];
        for (int &i : g[curr]) if (!vis[i]) subtree_sum += dfs(i, g, vals, k, vis);
        if (subtree_sum % k == 0) {
            res++;
            return 0;
        }
        return subtree_sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& vals, int k) {
        //given while tree sum % k == 0
        //if a node + left + right subtrees sum % k == 0, so
        //if its left/right subtree sum % k == 0 that means, 
        //node + right/left subtree sum % k == 0, and also if both left and 
        //right subtree sum % k == 0 individually, node val % k == 0 as well
        //so divide into components, calc subtree sum and if its % k == 0
        //it is a stand-alone component and res++ and return 0 so parent node
        //receives 0 sum from the child branch as that component is removed 
        //and by the above reasoning, if the whole curr_node + left + right 
        //sum % k == 0 and if one of the subtree sum % k == 0 then that means
        //curr_node + other subtree sum % k == 0 as well so all good
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        //need vis and cannot create a one-direction tree since edges given as
        //[0,2] [1,2] so 1 -> 2 and 0 -> 2 one directional edge created and no
        //way of reaching 1 so use bidirectional graph with vis rooted at 0
        for (auto& e : edges) g[e[1]].push_back(e[0]), g[e[0]].push_back(e[1]);
        dfs(0, g, vals, k, vis);
        return res;
    }
};