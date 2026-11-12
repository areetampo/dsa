class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> bucket(24 * 60, 0);
        for (auto &s : timePoints) {
            bucket[(((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0')))]++;
        }
        int first = 0;
        for (int x = 0; x < bucket.size(); x++) if (bucket[x]) {first = x; break;}
        if (bucket[first] > 1) return 0;
        int res = INT_MAX, i = first;
        for (int j = i + 1; j < bucket.size(); j++) {
            if (bucket[j] > 1) return 0;
            if (bucket[j]) {res = min(res, j - i),i = j;}
        }
        res = min(res, ((int)bucket.size() - 1 - i) + (first + 1));//circular since i is the last now
        return res;
    }
};