class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int s_ts = stoi(s.substr(0, 2)) * 60 * 60 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2)),
            e_ts = stoi(e.substr(0, 2)) * 60 * 60 + stoi(e.substr(3, 2)) * 60 + stoi(e.substr(6, 2));
        return s_ts > e_ts ? 86400 - e_ts + s_ts : e_ts - s_ts;
    }
};