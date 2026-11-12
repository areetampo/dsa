class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> res(n, 0);
        stack<int> s;
        s.push(n-1);
        for (int i = n-2; i >= 0; --i) {
            while (!s.empty() && v[s.top()] <= v[i]) s.pop();
            if (!s.empty()) res[i] = s.top() - i;//otherwise stays 0
            s.push(i);
        }
        return res;
    }
};