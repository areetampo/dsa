class Solution {
public:
    string decodeString(string s) {
        int curr_num = 0;
        vector<int> nums; vector<string> temp_str = {""};
        for (char& c : s) {
            if (isdigit(c)) {
                curr_num = curr_num * 10 + (c - '0');
            } else if (c == '[') {
                nums.push_back(curr_num);
                curr_num = 0;
                temp_str.push_back("");
            } else if (c == ']') {
                //appearance of ] means there exists a [ which means there 
                //exists a number before [ so nums never empty at this step
                string t = temp_str.back(); temp_str.pop_back();
                for (int i = 0; i < nums.back(); i++) temp_str.back() += t;
                nums.pop_back();
            } else {
                temp_str.back() += c;
            }
            // for (auto &i : nums) cout << i << " ";
            // cout << "\n"; for (auto &i : temp_str) cout << i << " ";
            // cout << "\ncurr_num: " << curr_num << " str: " << temp_str[0];
            // cout << "\n-----------\n";
        }
        return temp_str[0];
    }
};