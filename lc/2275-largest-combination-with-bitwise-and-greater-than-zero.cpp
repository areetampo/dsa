class Solution {
public:
    int largestCombination(vector<int>& v) {
        int a[24] = {0};
        for (int &i : v) {
            int idx = 0;
            while (i) {a[idx++] += i & 1; i >>= 1;}
        }
        return *max_element(a, a + 24);
    }
};