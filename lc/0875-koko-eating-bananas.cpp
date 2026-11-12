class Solution {
private:
    bool canEat(int m, const vector<int> &piles, int hours) {
        long long curr = 0;
        for (auto &pile : piles) {
            curr += pile/m + ((pile % m) ? 1 : 0);
            if (curr > hours) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        int ans = INT_MAX;
        int l = 1, h = 1e9, m = -1;//max piles[i] value
        //max pile that can eat at once (in 1h) 
        //more than that won't make sense as the time req to eat all the piles remains to be piles.size()
        while (l <= h) {
            m = l + (h-l)/2;
            if (canEat(m, piles, hours)) {
                ans = min(ans, m);
                h = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};