class Solution {
public:
    bool checkValidCuts(int N, vector<vector<int>>& a) {
        //a[i] = [bottom-left-x,y, top-right-x-y]
        //check horizontal cuts
        sort(a.begin(), a.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int cuts = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            int mx = a[i][3];
            while (i + 1 < n && a[i + 1][1] < mx) {
                mx = max(mx, a[i + 1][3]);
                i++;
            }
            cuts += i + 1 < n;
        }
        if (cuts >= 2) return true;
        sort(a.begin(), a.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        cuts = 0;
        for (int i = 0; i < n; i++) {
            int mx = a[i][2];
            while (i + 1 < n && a[i + 1][0] < mx) {
                mx = max(mx, a[i + 1][2]);
                i++;
            }
            cuts += i + 1 < n;
        }
        return cuts >= 2;
    }
};