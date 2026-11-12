class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque<int> d;
        for (int i = 0; i < k - 1; i++) {
            while (d.size() && v[d.front()] <= v[i]) d.pop_front();
            d.push_front(i);
        }
        vector<int> res;
        for (int i = k - 1; i < v.size(); i++) {
            cout << (d.size() ? d.back() : -1) << " " << (d.size() ? d.front() : -1) << endl;
            while (d.size() && d.back() <= i - k) d.pop_back();
            while (d.size() && v[d.front()] <= v[i]) d.pop_front();
            d.push_front(i);
            res.push_back(d.back());
        }
        for (int i = 0; i < res.size(); i++) res[i] = v[res[i]];
        return res;
    }
};