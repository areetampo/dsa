class Solution {
public:
    bool assign_gate_opening_time_by_bob(int i, vector<vector<int>>& g, vector<int>& gate_opening_time_by_bob, int curr_time) {
        gate_opening_time_by_bob[i] = curr_time;
        if (i == 0) return true;
        for (int& n : g[i]) {
            if (gate_opening_time_by_bob[n] == INT_MAX)
                if (assign_gate_opening_time_by_bob(n, g, gate_opening_time_by_bob, curr_time + 1))
                    return true;
        }
        gate_opening_time_by_bob[i] = INT_MAX;
        return false;
    }
    int max_net_value(int i, vector<vector<int>>& g, vector<int>& gate_opening_time_by_bob, vector<int>& amt, int curr_time) {
        // cout << i << "\n";
        int res = INT_MIN, temp = amt[i];
        amt[i] = INT_MAX;//signifies i is visited
        for (int& n : g[i]) {
            if (amt[n] != INT_MAX)
                res = max(res, max_net_value(n, g, gate_opening_time_by_bob, amt, curr_time + 1));
        }
        amt[i] = temp;
        int r = (res == INT_MIN ? 0 : res) + (gate_opening_time_by_bob[i] > curr_time ? amt[i] : 
            gate_opening_time_by_bob[i] == curr_time ? amt[i] / 2 : 0);
        // cout << i << " " << res << " " << r << "\n";
        return r;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        //bob is a leaf node, only 1 path from bob node to root node 0
        //suppose the path has 5 nodes ->
        //now as bob traverses, each step, amt[node in path] value must be changed
        //so that when alice travels from root node 0 to some leaf node, maximum
        //amt nodes can be chosen, BUT...
        //consider the 5 node path of bob for example, it reaches the 4th node at
        //step 4 and lets say its amt[] < 0 so bob will open that gate and set its
        //amt[] = 0 -> BUT this doesnt mean that alice would have to 0 net added to
        //her path when passing that node BECAUSE, lets say root node 0 has only 1
        //neighbor (which is the 4th node from leaf node bob to root node 0)
        //so this will definitely by 2nd node fr alice and bob reaches it in step 4
        //so alice will have to deal with opening that gate and add -ve amount to her
        int n = amt.size();
        vector<int> gate_opening_time_by_bob(n, INT_MAX);
        vector<vector<int>> g(n, vector<int>());
        for (auto &i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        assign_gate_opening_time_by_bob(bob, g, gate_opening_time_by_bob, 0);
        for (int& i : gate_opening_time_by_bob) cout << i << " "; cout << "\n";
        return max_net_value(0, g, gate_opening_time_by_bob, amt, 0);

    }
};