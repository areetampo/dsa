class Solution {
public:
    int getLargestOutlier(vector<int>& v) {
        int sum = accumulate(v.begin(), v.end(), 0);
        unordered_map<int, int> m;
        for (int &i : v) m[i]++;
        int res = -1001;
        for (int &i : v) {
            sum -= i;
            if (--m[i] == 0) m.erase(i);
            if (sum % 2 == 0) {
                int specialSum = sum / 2;
                if (m.find(specialSum) != m.end()) res = max(res, i);//i is outlier
            }
            m[i]++;
            sum += i;
        }
        return res;
    }
};