class Solution {
public:
    int n; vector<int> v; vector<vector<int>> res;
    void f(int i, long long target, int k, vector<int>& t) {
        if (n - i < k) return;
        if (k == 2) {
            int s = i, e = n - 1;
            while (s < e) {
                if (v[s] + v[e] == target) {
                    t.push_back(v[s]); t.push_back(v[e]);
                    res.push_back(t);
                    t.pop_back(); t.pop_back();
                    while (s + 1 < e && v[s] == v[s + 1]) s++;
                    while (s < e - 1 && v[e - 1] == v[e]) e--;
                    s++; e--;
                } else if (v[s] + v[e] > target) e--;
                else s++;
            }
            return;
        }
        t.push_back(v[i]);
        f(i + 1, target - v[i], k - 1, t);
        t.pop_back();
        int curr = v[i];
        while (n - i >= k && v[i] == curr) i++;//skip duplicates
        f(i, target, k, t);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target, int k = 4) {//generalised for k sum
        n = nums.size();
        res = vector<vector<int>>();
        v = vector<int>(nums); sort(v.begin(), v.end());
        vector<int> t;
        f(0, target, k, t);
        return res;
    }
};