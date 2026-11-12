class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //no dfs as res not sorted since goes to 1 depth eg: 12345 then foes to 2345
        vector<int> res;
        queue<int> q;
        for (int i = 1; i < 9; ++i) q.push(i);
        while (!q.empty()) {
            int f = q.front(); q.pop();
            if (f > high) break;
            if (f >= low) res.push_back(f);
            if (f % 10 != 9) q.push(f * 10 + f % 10 + 1);
        }
        return res;
    }
};