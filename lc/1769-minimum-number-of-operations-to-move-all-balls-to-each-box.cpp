class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size(), right_boxes = 0, right_moves = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                right_boxes++;
                right_moves += i;
            }
        }
        vector<int> res;
        for (int i = 0, left_boxes = 0, left_moves = 0; i < n; i++) {
            cout << right_boxes << " " << right_moves << "\n";
            res.push_back(left_moves + right_moves);
            left_boxes += s[i] == '1';
            left_moves += left_boxes;
            right_moves -= right_boxes;
            if (i + 1 < n) right_boxes -= s[i + 1] == '1';
        }
        return res;
    }
};