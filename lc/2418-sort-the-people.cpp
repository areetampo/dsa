class Solution {
public:
    vector<string> sortPeople(vector<string>& na, vector<int>& h) {
        int n = na.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [h](int a, int b){
            return h[a] > h[b];
        });
        vector<string> res;
        for (int &i : idx) {
            res.push_back(na[i]);
        }
        return res;
    }
};