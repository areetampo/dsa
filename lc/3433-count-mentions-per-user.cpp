class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        //OFFLINE -> user goes offline for 60 units, back at offline_time + 60
        //MESSAGE -> 
        //ALL : all users counted
        //HERE : only online users counted
        //<id> : these users only mentioned (can include offline ones as well)
        //user coming back online (initially all online) or going offline
        //(offline / online processed before message query on that timestamp)
        //approach ->
        //maintain map of each user's status -> (offline/online 0/1)
        //sort the events by timestamp, while traversing if q.front <= current's
        //timestamp, remove from q and toggle those user's status to be online
        //and for offline query, put in q end with <timestamp + 60, user_id>
        queue<pair<int, int>> q;
        sort(e.begin(), e.end(), [](const auto& a, const auto& b){
            //if same timestamp, then offline query processed first
            //so O of offline and M of message, take O to be first
            int A = stoi(a[1]), B = stoi(b[1]);
            return A == B ? a[0][0] > b[0][0] : A < B;
        });
        vector<int> res(n, 0), status(n, 1);
        int all = 0;
        for (auto &i : e) {
            string type = i[0], users = i[2];
            int timestamp = stoi(i[1]);
            // cout << "{" << type << "," << timestamp << "," << users << "}\n";
            while (!q.empty() && q.front().first <= timestamp) {
                status[q.front().second] = 1;
                q.pop();
            }
            if (type == "OFFLINE") {
                //only 1 user for offline query
                int user = stoi(users);
                q.push({timestamp + 60, user});
                status[user] = 0;
            } else {
                if (users == "ALL") all++;
                else if (users == "HERE") {
                    for (int j = 0; j < n; j++) {
                        res[j] += status[j];
                    }
                } else {
                    for (int j = 2; j < users.size(); j += 3) {
                        int user = 0;
                        while (j < users.size() && users[j] != ' ') {
                            user = user * 10 + (users[j] - '0');
                            j++;
                        }
                        res[user]++;
                    }
                }
            }
            // for (int &j : res) cout << j << " "; cout << "\n";
            // for (int &j : status) cout << j << " "; cout << "\n---\n";
        }
        transform(res.begin(), res.end(), res.begin(), [all](const int& i){
            return i + all;
        });
        return res;
    }
};