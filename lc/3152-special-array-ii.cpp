class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        vector<bool> res;
        if (n == 1) {
            for (auto &i : q) res.push_back(i[0] + i[1] == 0);
            return res;
        }
        //first number always special so put 1
        vector<int> d = {1};
        for (int i = 0; i < n - 1; i++) {
            d.push_back(abs((v[i] % 2) - (v[i + 1] % 2)));
        }
        partial_sum(d.begin(), d.end(), d.begin());
        // for (int &i : d) cout << i << " ";
        //1 2 3 4 5 arr
        //1 1 1 1 1 ->
        //1 2 3 4 5 d
        //q = 1,4 indices that is elements 2 to 5 of arr
        //1 3 3 4 5 arr
        //1 0 0 1 1 ->
        //1 1 1 2 3 d 
        //q = 1,4 indices that is elements 3 (first) to 5 of arr
        for (auto &i : q) {
            int s = i[0], e = i[1];
            if (s == e) res.push_back(1);//single element
            else res.push_back(e - s == d[e] - d[s]);
        }
        return res;
    }
};