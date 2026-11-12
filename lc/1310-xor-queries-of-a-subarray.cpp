class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> x(arr.size() + 1, 0), res;
        for (int i = 0; i < arr.size(); i++) x[i + 1] = x[i] ^ arr[i];
        for (auto i : queries) res.push_back(x[i[1] + 1] ^ x[i[0]]);
        return res;
    }
};