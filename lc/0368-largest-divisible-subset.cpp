class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<int> dp(v.size(), 0);
        dp[0] = 1;
        int mx = 0;
        for (int i = 1; i < v.size(); ++i) {
            int j = i;
            int mxVal = 0;//from dp before i
            while (--j >= 0) if (v[i] % v[j] == 0) mxVal = max(mxVal, dp[j]);
            dp[i] = 1 + mxVal;//since divisibele, incerement set size since i th also added
            if (dp[i] > dp[mx]) mx = i;//keep track of max el in dp (max set size)
            cout << v[i] << " " << dp[i] << endl;
        }
        vector<int> res = {v[mx]};//now start from largest set size's largest el
        int i = mx;
        while (res.size() != dp[mx]) {
            int j = i;
            int mxValIdx = -1;//look for value which is divisible (included in set) and
            while (--j >= 0) {//the subset size is maximum available (note that nums divisible in left
                if (v[i] % v[j] == 0) {//will have less value in dp than dp[i] (largest el of the res set))
                    if (mxValIdx == -1) mxValIdx = j;
                    if (dp[j] > dp[mxValIdx]) mxValIdx = j;
                }
            }
            res.push_back(v[mxValIdx]);
            i = mxValIdx;
        }
        reverse(res.begin(), res.end());//ascending now
        return res;
    }
};