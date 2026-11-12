class Solution {
public:
    static vector<int> facts;
    void init() {
        static bool done = false;
        if (done) return;
        done = true;
        facts.resize(10); 
        facts[0] = facts[1] = 1;
        for (int i = 2; i <= 9; i++) {
            facts[i] = facts[i - 1] * i;
        }
    }
    string getPermutation(int n, int k) {
        init();
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        string res = "";
        for (int i = 1; i <= n; i++) {
            int f = facts[n - i];
            int index = max(0, (k + f - 1) / f - 1);
            res += to_string(v[index]);
            v.erase(v.begin() + index); // for O(log n) use fenwick tree
            k -= f * ((k + f - 1) / f - 1);
        }
        return res;
    }
};
vector<int> Solution::facts;