class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        vector<int> s;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.back() > v[i]) s.pop_back();
            int t = v[i];
            v[i] -= s.empty() ? 0 : s.back();
            s.push_back(t);
        }
        return v;
    }
};