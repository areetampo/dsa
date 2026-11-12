class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        //method 1 using sort
        //method 2 without using nlogn sort but counting sort using int array from 1 to 1e5
        vector<int> c(1e5+1, 0);
        for (int &i : v) {
            ++c[i];
        }
        int i = 0, j = 0;
        while (j <= 1e5) {
            while (c[j]--) v[i++] = j; 
            j++;
        }
        vector<vector<int>> res;
        for (int i = 0; i < v.size() - 2; i += 3) {
            if (v[i+2] - v[i+1] > k || v[i+1] - v[i] > k || v[i+2] - v[i] > k) return vector<vector<int>> (0);
            res.push_back({v[i], v[i+1], v[i+2]});
        }
        return res;
    }
};