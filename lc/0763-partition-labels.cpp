class Solution {
public:
    vector<int> partitionLabels(string s) {
        int end[26], n = s.size();
        fill(end, end + 26, -1);
        for (int i = 0; i < n; i++) end[s[i] - 97] = i;
        vector<int> res;
        for (int i = 0, max_end = 0, len = 0; i < n; i++) {
            max_end = max(max_end, end[s[i] - 97]);
            if (i == max_end)
                res.push_back(i + 1 - len), max_end = -1, len += res.back();
        }
        return res;
    }
};