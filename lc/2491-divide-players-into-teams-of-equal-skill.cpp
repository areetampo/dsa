class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        //v.len <= 1e5, v[i] <= 1000
        int skill = accumulate(v.begin(), v.end(), 0) / (v.size() / 2);// = 1e8 / 500 = 1e6 / 5 = 2 * 1e5
        int f[200001] = {};
        for (int &i : v) {
            if (i >= skill) return -1;//pair cannot be formed
            f[i]++;
        }
        //now f[i] == f[skill - i] so that a 'pair' of players with their sum = skill
        long long r = 0;//chemistry
        //since one of the players must have their v[i] <= skill / 2 then only 2 players will have their total == skill
        for (int i = 1; i <= skill / 2; i++) {
            if (f[i] != f[skill - i]) return -1;
            if (f[i]) //players with i, skill - i must exist in v[] to calc chem
            r += (long long)i * (skill - i) * (i == skill - i ? f[i] / 2 : f[i]);
            //last * cuz players with i, skill - i can be many (multiple pairs)
            //not using just * f[i] to avoid players with same skill from doubling the chemistry, eg:
            //skill = 6 (req), 2 (f[i]) players with skill = 3 (i) | so * f[i] == * 2
        }
        return r;
    }
};