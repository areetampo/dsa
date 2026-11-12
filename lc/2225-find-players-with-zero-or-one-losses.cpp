class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        //not lost any match, lost 1 match
        vector<vector<int>> res(2, vector<int>());

        map<int, int> losses;
        for (int i = 0; i < m.size(); ++i) {
            if (losses.find(m[i][0]) == losses.end()) losses[m[i][0]] = 0;
            ++losses[m[i][1]];
        } 

        for (auto i = losses.begin(); i != losses.end(); ++i) {
            if (!i->second) res[0].push_back(i->first);
            if (i->second == 1) res[1].push_back(i->first);
        }
        
        return res;
    }
};