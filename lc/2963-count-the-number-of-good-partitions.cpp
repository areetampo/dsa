class Solution {
public:
    int mod = 1e9 + 7;
    int power(long long base, int expo) {
        long long res = 1;
        while (expo) {
            if (expo % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            expo >>= 1;
        }
        return res;
    }
    int numberOfGoodPartitions(vector<int>& v) {
        int n = v.size(), sections = 0, res = 1;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) m[v[i]] = i;
        for (int i = 0, curr_section_max_idx = 0; i < n; i++) {
            int last_occurence = m[v[i]];
            curr_section_max_idx = max(curr_section_max_idx, last_occurence);
            if (curr_section_max_idx == i) {
                sections++;
                if (i < n - 1) res = res * 2 % mod;
            }
            // cout << i << " " << curr_section_max_idx << " " << sections << "\n";
        }
        //ways to insert (sections - 1) number of partitions
        // return power(2, sections - 1);
        return res;
    }
};