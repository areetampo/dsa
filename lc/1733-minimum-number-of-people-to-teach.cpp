class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //there are n languages and languages.size() users
        //hash the languages per user to easy lookup
        vector<unordered_set<int>> langs(languages.size());
        for (int i = 0; i < languages.size(); i++) {
            for (int &j : languages[i]) langs[i].insert(j);
        }
        //v[i] language can be learned by v[i].size() number of users
        vector<unordered_set<int>> v(n + 1);//languages 1 -> n
        for (auto &i : friendships) {
            //set of languages known by both
            auto &a = langs[i[0] - 1], &b = langs[i[1] - 1];
            bool common_exists = 0;
            for (auto &l : a) if (b.find(l) != b.end()) {
                common_exists = 1; break;
            }
            //if both have no common language then they cannot communicate
            //so for all 1-> n languages -> i[0] or i[1] person can learn them
            if (common_exists == 0) {
                for (int l = 1; l <= n; l++) {
                    if (a.find(l) == a.end()) v[l].insert(i[0]);
                    if (b.find(l) == b.end()) v[l].insert(i[1]);
                }
            }
        }
        //in end each i represents the language and v[i] is the set of users
        //which can communicate with friend from learning them, so the
        //min number of users that can learn a language and benefit from it req
        int res = languages.size();//total number of users
        for (int i = 1; i <= n; i++) {
            // cout << i << ": ";
            // for (auto &j : v[i]) cout << j << " "; cout << "\n"; 
            res = min(res, (int)v[i].size());
        }
        return res;
    }
};