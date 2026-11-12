class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &w : words)
        if (equal(begin(w), end(w), rbegin(w)))
            return w;
        return  "";
    }
};