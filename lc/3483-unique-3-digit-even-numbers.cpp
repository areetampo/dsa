class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int x : digits) cnt[x]++;

        int ans = 0;

        for (int h = 1; h <= 9; h++) {
            for (int t = 0; t <= 9; t++) {
                for (int u = 0; u <= 8; u += 2) {

                    int need[10] = {};
                    need[h]++;
                    need[t]++;
                    need[u]++;

                    bool ok = true;

                    for (int d = 0; d < 10; d++) {
                        if (need[d] > cnt[d]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) ans++;
                }
            }
        }

        return ans;
    }
};