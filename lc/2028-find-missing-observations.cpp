class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        //(sum + leftoverSum) / (n + m) = mean
        int x = mean * n - sum + mean * rolls.size();
        cout << x;
        if (x < n || x > n * 6) return {};//using all 1s (min) or all 6s (max) doesnt satisfy res sum = x
        vector<int> res(n, x / n);
        for (int i = 0; i < x % n; i++) {
            res[i]++;
        }
        return res;
    }
};