class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n = pos.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return pos[i] < pos[j];
        });
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int I = idx[i];
            if (d[I] == 'R') s.push(I);
            else {
                while (s.size() && d[s.top()] == 'R' && h[s.top()] <= h[I]) {
                    h[I] = h[s.top()] < h[I] ? h[I] - 1 : 0;
                    h[s.top()] = 0;
                    s.pop();
                }
                if (h[I]) {
                    if (s.size() && d[s.top()] == 'R') {
                        h[s.top()]--;
                        h[I] = 0;
                    }
                    //s.size() = 0 or direction is L so push
                    else s.push(I);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (h[i]) res.push_back(h[i]);
        }
        return res;
    }
};