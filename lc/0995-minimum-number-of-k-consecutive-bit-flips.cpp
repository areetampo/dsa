class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        int flips = 0, res = 0, n = v.size();
        for (int i = 0; i < n; i++) {
            if (i >= k && v[i - k] == 2) flips--;//end of the k size subarr
            if ((v[i] + flips) % 2 == 0) {
                flips++;
                res++;
                v[i] = 2;//marks start of k size subarr
            }
        }
        if (v[n - k] == 2) flips--;
        return flips ? -1 : res;
    }
};