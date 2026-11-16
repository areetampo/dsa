class Solution {
public:
    static vector<vector<int>> res;

    void init() {
        static bool done = false;
        if (done) return;
        done = true;
        res.resize(31);
        res[1] = {1};
        res[2] = {1, 1};
        for (int i = 3; i <= 30; i++) {
            res[i].push_back(1);
            for (int j = 1; j < res[i - 1].size(); j++) {
                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res[i].push_back(1);
        }
    }

    vector<vector<int>> generate(int n) {
        init();
        return vector<vector<int>>(res.begin() + 1, res.begin() + n + 1);
    }
};

vector<vector<int>> Solution::res;