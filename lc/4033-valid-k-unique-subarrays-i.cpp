class Solution {
public:
    vector<bool> validSubarrays(vector<int>& v, int k, vector<vector<int>>& q) {
        int n = v.size(), B = sqrt(n);
        vector<int> qi(q.size());
        iota(qi.begin(), qi.end(), 0);
        sort(qi.begin(), qi.end(), [&](int a, int b) {
            int block_a = q[a][0] / B;
            int block_b = q[b][0] / B;

            if (block_a != block_b)
                return block_a < block_b;

            return q[a][1] < q[b][1];
        });

        unordered_map<int, int> f;
        int cur_l = 0, cur_r = -1, distinct = 0, even = 0;
        auto add = [&](int i) {
            distinct += ++f[i] == 1;
            even += f[i] == 1 ? 0 : f[i] % 2 == 0 ? 1 : -1;
        };
        auto remove = [&](int i) {
            distinct -= --f[i] == 0;
            even += f[i] == 0 ? 0 : f[i] % 2 == 0 ? 1 : -1;
        };

        vector<bool> res(q.size());

        for (int i : qi) {
            int l = q[i][0], r = q[i][1];

            // adds first then removes
            while (cur_l > l) add(v[--cur_l]);
            while (cur_r < r) add(v[++cur_r]);
            while (cur_l < l) remove(v[cur_l++]);
            while (cur_r > r) remove(v[cur_r--]);

            res[i] = distinct == k && even == k;
        }

        return res;
    }
};