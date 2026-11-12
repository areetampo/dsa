class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        //initial thought is to:
        //for each row:
        //flip all 0s to 1s and the cols which were flipped, flip them in all other 
        //n - 1 rows as well while computing the total num of rows where all 1s exist
        //note that doing vice versa is not necessary (changing row's 1s to 0s) since
        //the affected cols, they flip the same col in other rows as well
        //so in end if a row were to become all 0s or 1s after flipping out 0s to 1s
        //(of chosen row) then vice versa (flipping the said rows 1s to 0s) will
        //just reverse the chosen bits in other cols and if they were making a row
        //with all 1s / 0s those rows would still make all 0s / 1s so total num of
        //rows remain unaffected
        //now this approach goes to each row and traverses whose matrix for it 
        //O(n * n * m) time
        //better approach:
        //note that what we are doing is basically trying to find identical row
        //patterns eg row1 = 001100 row2 = 110011 row3 = 001100 then considering
        //row1: flipping 1s / 0s to 0s / 1s will have the chosen cols in other rows
        //also making all 1s or 0s so basically the pattern must be same only those
        //rows will be considered, now to avoid redundancy, all rows with same pattern
        //must not be checked again hence reducing time
        //now a better way to arrive at the answer will be to simply find the most
        //common patters: maximum number of rows with the same pattern 
        //USE COUNTING TO FORM STRING
        unordered_map<string, int> mp;
        for (auto &r : m) {
            string s = "";
            int i = 0;
            while (i < m[0].size()) {
                int j = i;
                while (j + 1 < m[0].size() && r[j] == r[j + 1]) j++;
                s += to_string(j - i + 1) + '.';
                //add dot to separate 1s and 0s count concatenated in rows 
                //cuz diff patterns can give same string
                //eg: [[1,11 0s], [0, 11 1s]] -> strings would be 111, 111 (same but patterns are diff actually)
                i = j + 1;
            }
            mp[s]++;
        }
        for (auto it : mp) cout << it.first << " " << it.second << "\n";
        return max_element(
            mp.begin(), mp.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; }
        )->second;
    }
};