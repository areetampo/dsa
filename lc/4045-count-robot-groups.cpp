class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& speed, int d) {
        int n = pos.size();
        // t = 0 merge possible
        // that should be considered inital state and movement starts then
        vector<int> sp;
        for (int i = 0, j; i < n; i = j + 1) {
            j = i;
            while (j + 1 < n && pos[j + 1] - pos[j] <= d) j++;
            sp.push_back(speed[j]);
        }

        // now all merged groups at dist > d and start moving with rightmost robo speed
        // say sp = 5 4 2 3
        // group moving with speed 2 never meets 3
        // 5 or 4 never meet 3 either, at max they combine with 2 and whole group moves with 2
        // say sp = 5 4 2 3 2
        // eventually 2 groups both moving with speed 2, will never meet
        // say sp = 5 4 2 3 2 1
        // eventually groups 2 2 1 second 2 meets 1 and 2nd and 3rd group move with speed 1
        // the first gorup with speed 2 catches up and eventually combine to form 1 group moving with speed 1

        stack<int> t;
        for (int i = 0; i < sp.size(); i++) {
            while (!t.empty() && t.top() > sp[i])
                t.pop();
            t.push(sp[i]);
        }

        return t.size();
    }
};