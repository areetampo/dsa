class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        return accumulate(d.begin(), d.end(), 0, [](const int& a, const int& b){
            return a ^ b;
        }) == 0;
    }
};