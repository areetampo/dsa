class Solution {
public:
    bool checkIfExist(vector<int>& v) {
        unordered_set<int> s;
        for (int &i : v) {
            if (i % 2 == 0 && s.find(i / 2) != s.end() || s.find(i * 2) != s.end()) return 1;
            s.insert(i);
        }
        return 0;
    }
};