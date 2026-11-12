class Solution {
public:
    int root(int i) {
        int j = 2;
        while (j * j < i) j++;
        return j * j == i ? j : -1;
    }
    int longestSquareStreak(vector<int>& v) {//extend left and right like lc 128
        //v[i] <= 1e5 so max length seq 5 possible, min must be 2
        //v[i] != 1
        unordered_map<int, int> m;
        for (int &i : v) m[i] = 0;//not considered yet
        int res = 0;
        for (int &i : v) {
            if (m[i] == 1) continue;//was marked in a seq previously
            m[i] = 1;//mark considered
            int seq = 1, orig = i;
            while (i <= 1e5 / i && m.find(i * i) != m.end()) {
                seq++;
                i *= i;
                m[i] = 1;
            }
            i = orig;
            while (m.find(root(i)) != m.end()) {
                seq++;
                i = root(i);
                m[i] = 1;
            }
            res = max(res, seq);
        }
        return res == 1 ? -1 : res;
    }
};