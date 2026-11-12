class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> m;
        for (int &i : a) m[i]++;
        int r = 0;
        for (auto& [k, v] : m) {
            //k = potential same color rabbits
            //v = how many rabits saying that
            if (k + 1 == v) r += v;
            else if (k + 1 < v) {
                //eg 7 saying 3 have same color
                //breakdown to 4 saying 3 same so r += 4
                r += v / (k + 1) * (k + 1);
                v %= k + 1;
            }
            //now left with 3 saying 3 same color
            if (v > 0 && v < k + 1) {
                r += k + 1;
            }
        }
        return r;
    }
};