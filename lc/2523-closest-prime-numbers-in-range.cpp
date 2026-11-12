class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool seive[(int)1e6 + 1] = {};
        for (int i = 2; i <= 1e6; i++) {
            if (seive[i] == true) continue;
            for (int j = 2 * i; j <= 1e6; j += i) {
                seive[j] = true;
            }
        }
        vector<int> prime;
        for (int i = 2; i <= 1e6; i++) if (seive[i] == false) prime.push_back(i);
        vector<int> res = {-1, -1}; int gap = 1e6;
        int i = 0;
        // for (int& k : prime) cout << k << " "; cout << "\n";
        while (i < prime.size() && prime[i] < left) {
            i++; 
            // cout << prime[i] << " ";
        }
        // cout << prime[i] << "\n";
        while (i + 1 < prime.size() && prime[i + 1] <= right) {
            // cout << prime[i] << " " << prime[i + 1] << "\n";
            if (prime[i + 1] - prime[i] < gap) {
                gap = prime[i + 1] - prime[i];
                res = {prime[i], prime[i + 1]};
                // if (gap <= 2) break;
            }
            i++;
        }
        return res;
    }
};