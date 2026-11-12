class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        //every node has judge as direct neighbor
        //judge has no neighbor nodes
        //there is only one judge
        //do incoming - outgoing
        vector<int> a(n+1, 0);//1 to n nodes
        for (auto& e : t) {
            a[e[0]]--;
            a[e[1]]++;
        }
        for (auto& i : a) cout << i << " ";
        int res = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == n - 1) {
                if (res != -1) return -1;
                res = i;
            }
        }
        return res;
    }
};