class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> d(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        queue<string> q;
        q.push("0000");
        int res = -1;
        while (!q.empty()) {
            ++res;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string front = q.front(); q.pop();
                // cout << front << ", add: ";
                if (d.find(front) != d.end()) continue;
                if (front == target) return res;
                if (vis.find(front) == vis.end()) {
                    vis.insert(front);
                    for (int j = 0; j < 4; j++) {
                        int digit = front[j] - '0';
                        digit = (digit + 1) % 10;
                        front[j] = digit + '0';
                        if (vis.find(front) == vis.end()) {
                            // cout << front << " ";
                            q.push(front);
                        }
                        digit = (digit - 2 + 10) % 10;
                        front[j] = digit + '0';
                        if (vis.find(front) == vis.end()) {
                            // cout << front << " ";
                            q.push(front);
                        }
                        digit = (digit + 1) % 10;
                        front[j] = digit + '0';
                    }
                    // cout << res;
                }
                // cout << endl;
            }
            // cout << endl;
        }
        return -1;
    }
};