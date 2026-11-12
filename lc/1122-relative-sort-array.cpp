class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int &i : arr1) m[i]++;
        int idx = 0;
        for (int &i : arr2) {
            while (m[i]--) arr1[idx++] = i;
        }
        for (auto &i : m) while (i.second-- > 0) arr1[idx++] = i.first;
        return arr1;
    }
};