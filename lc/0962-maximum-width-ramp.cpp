class Solution {
public:
    int maxWidthRamp(vector<int>& v) {
        stack<int> s;//stack
        for (int i= 0; i < v.size(); i++) {
            if (s.size() == 0 || v[s.top()] >= v[i]) s.push(i);
        }
        //stack vals are inc (indices) and v[vals] is dec so in reverse order for each val 
        //remove elements from stack until maximum value smaller than v[i] is reached and
        //i - stack.top will give the max ramp width possible condiresing the i th element
        int res = 0;
        for (int i = v.size() - 1; i >= 0 && s.size(); i--) {
            while (s.size() && v[s.top()] <= v[i]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        return res;
    }
};