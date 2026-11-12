class Solution {
public:
    string convert(string s, int r) {
        if (r == 1) return s;
        string res = ""; int n = s.length();
        for (int i = 0; i < r; i++) {
            int j = i;
            while (j < n) {
                res += s[j];
                // P A H N
                // APLSIIG
                // Y I R
                j += 2 * (r - i - 1);//going to har in next col of same row eg: P -> A
                if (i && j < n) {//eg: landed at P in second row so take it then go to L
                    if (i != r - 1) res += s[j];//last row no char before and r - i - 1 = 0 so to prevent s[j] twice
                    j += 2 * i;//eg: from Y in last row col 1 to I in next col
                }
            }
        }
        return res;
    }
};