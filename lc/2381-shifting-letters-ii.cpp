class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size() + 1, 0);
        for (auto &i : shifts) {
            //1 forward shift, -1 backward shift
            v[i[0]] += i[2] == 1 ? 1 : -1;
            v[i[1] + 1] += i[2] == 1 ? -1 : 1;
        }
        for (int i = 0, sum = 0; i < s.size(); i++) {
            sum += v[i];
            int move = sum % 26, ch = s[i] - 97, new_ch = (((ch + move) % 26) + 26) % 26;    
            s[i] = new_ch + 97;
        }
        return s;
    }
};