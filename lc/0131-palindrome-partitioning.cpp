class Solution {
public:
    bool isPalindrome(string& s) {
        for (int i = 0; i <= s.length()/2; i++) {
            if (s[i] != s[s.length() - 1 - i]) return 0;
        }
        return 1;
    }
    void dfs(int start, int end, string& s, vector<string>& curr, vector<vector<string>>& res) {
        //base cases
        if (start == s.length()) {//start to end previously was a palindrome so start = end = s.length() now
            res.push_back(curr);
            return;
        }
        if (end == s.length()) return;//start lies in string while end has reached outside the string, extra info
        //will only happen when the below dfs is executed
        //work
        string sub = s.substr(start, end - start + 1);
        if (isPalindrome(sub)) {//if substr from idx start to end is a palidrome 
            curr.push_back(sub);
            dfs(end + 1, end + 1, s, curr, res);//now go to next idx and start checking from it
            curr.pop_back();//remove cuz next we will check for aa longer palindrome from start idx
        }
        dfs(start, end + 1, s, curr, res);//check for longer irrespective of whether start to end is a palindrome or not
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(0, 0, s, curr, res);
        return res;
    }
};