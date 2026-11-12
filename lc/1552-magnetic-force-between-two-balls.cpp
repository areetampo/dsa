class Solution {
public:
    bool canPut(vector<int>& v, int balls, int gap) {
        int n = v.size();
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && v[j] - v[i] < gap) j++;
            if (j != n) balls--;
            i = j;
        }
        return balls <= 1;//first ball alr placed at idx = 0
    }
    int maxDistance(vector<int>& position, int m) {
        //if min gap between 2 balls (adjacent obviously) is x then x - 1 as min gap also possible
        sort(position.begin(), position.end());
        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mi = (lo + hi) >> 1;
            if (canPut(position, m, mi)) lo = mi + 1;
            else hi = mi - 1;
            // cout << lo << " " << hi << endl;
        }
        return hi;
    }
};