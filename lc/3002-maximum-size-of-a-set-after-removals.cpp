class Solution {
public:
    int maximumSetSize(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        unordered_map<int, int> a;
        unordered_map<int, int> b;
        for (int &i : n1) ++a[i];
        for (int &i : n2) ++b[i];
        // if (a.size() <= n/2 && b.size() <= n/2) {
        //     unordered_set<int> res;
        //     for (auto it = a.begin(); it !=a.end(); ++it) res.insert(it->first);
        //     for (auto it = b.begin(); it !=b.end(); ++it) res.insert(it->first);
        //     return res.size();
        // }
        // else if (a.size() > n/2 && b.size() > n/2) {
        //     return n;
        // }
        // else {//one array contains > n/2 unique elements 
            unordered_set<int> c;//store teh common element value among both arrays
            for (auto it = a.begin(); it !=a.end(); ++it) {
                if (b.contains(it->first)) c.insert(it->first);
            }
            unordered_map<int, int> use = (a.size() > n/2) ? a : b;//set we need to delete from to make n/2 els
            unordered_map<int, int> other = (a.size() > n/2) ? b : a;
            vector<pair<int, int>> u;//store freq in dec order
            for (auto it = use.begin(); it !=use.end(); ++it) u.push_back({it->first, it->second});
            sort(u.begin(), u.end(), [](pair<int, int> &a, pair<int, int> &b){
                return a.second > b.second;
            });
            int del = n/2;//num of els to delete from useMap
            for (auto &i : u) {//remove commons starting from the el with highest freq
                if (del <= 0) break;
                if (c.find(i.first) != c.end()) {
                    del -= i.second;
                    i.second = 0;
                    use[i.first] = 0;
                }
            }
            vector<pair<int, int>> uu;//remove the els whose freq made 0
            for (auto &i : u) {
                if (i.second != 0) uu.push_back(i); 
                else use.erase(i.first);//del 0 freq from useMap
            }
            u = uu;
            sort(u.begin(), u.end(), [](pair<int, int> &a, pair<int, int> &b){
                return a.second > b.second;
            });
            for (auto &i : u) {//still < n/2 els deleted so make highest freq els freq to 1 deleting other occurences
                if (del <= 0 || i.second == 1) break;
                del -= i.second - 1;
                i.second = 1;
                use[i.first] = 1;
            }
            if (del > 0)//still < n/2 els deleted and all freq = 1 now
            for (auto it = use.begin(); it !=use.end(); ++it) {
                if (del--) it->second = 0;
                else break;
            }
            unordered_set<int> res;
            for (auto it = use.begin(); it !=use.end(); ++it) if (it->second != 0) res.insert(it->first);
            for (auto it = other.begin(); it !=other.end(); ++it) res.insert(it->first);
            return min(n, (int)res.size());
        // }        
    }
};