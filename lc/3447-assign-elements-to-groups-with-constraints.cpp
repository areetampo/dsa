class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        //res[i] = smallest j for which g[i] % e[j] = 0
        //m1 TLE
        //create seive of 1e6 elements and assign seive[num] = min index of num in e
        //now for i: 1 to 1e6
        //assign multiples of i with their curr min index
        //now for every g[i], seive[g[i]] has the smallest index of a divisor of it
        //present in e[]
        // vector<int> seive(1e6 + 1, -1), res;
        // for (int i = 0; i < e.size(); i++) {
        //     if (seive[e[i]] == -1) seive[e[i]] = i;
        //     else seive[e[i]] = min(seive[e[i]], i);
        // }
        // for (int i = 1; i <= 1e6/2; i++) {
        //     if (seive[i] == -1) continue;
        //     for (int j = 2 * i; j <= 1e6; j += i) {
        //         if (seive[j] == -1) seive[j] = seive[i];
        //         else seive[j] = min(seive[i], seive[j]);
        //     }
        // }
        // for (int& i : g) res.push_back(seive[i]);
        // return res;
        //m2
        //create seive of 1e6 elements and assign seive[num] = min index of num in e
        //then for each g[i], find all its factors (1 -> sqrt(g[i])) and pick the one
        //whose present in seive with min index
        vector<int> seive(1e6 + 1, -1), res;
        for (int i = 0; i < e.size(); i++) {
            if (seive[e[i]] == -1) seive[e[i]] = i;
            else seive[e[i]] = min(seive[e[i]], i);
        }
        for (int& i : g) {
            res.push_back(INT_MAX);
            for (int j = 1; j <= sqrt(i); j++) {
                if (i % j != 0) continue;
                int a = i / j, b = j;
                if (seive[a] != -1) res.back() = min(res.back(), seive[a]);
                if (seive[b] != -1) res.back() = min(res.back(), seive[b]);
            }
            if (res.back() == INT_MAX) res.back() = -1;
        }
        return res;
    }
};