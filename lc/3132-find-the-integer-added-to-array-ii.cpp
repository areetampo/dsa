class Solution {
public:
    int f(int skipAvailable, vector<int>& n1, vector<int>& n2) {
        int x = skipAvailable == 2 ? n2[0] - n1[0] : skipAvailable == 1 ? n2[0] - n1[1] : n2[0] - n1[2];
        int i = skipAvailable == 2 ? 0 : skipAvailable == 1 ? 1 : 2, j = 0;
        for (; i < n1.size() && j < n2.size(); ++i) {
            if (n2[j] - n1[i] == x) ++j;
            else if (skipAvailable) --skipAvailable;
            else return INT_MAX;
        }
        return x;
    }
    int minimumAddedInteger(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        return min(f(0, n1, n2), min(f(1, n1, n2), f(2, n1, n2)));
    }
};