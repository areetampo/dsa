class TaskManager {
public:
    //just keep putting everything in pq: all added tasks, edited tasks
    //but in map, keep track of their latest status: if task is deleted
    //dont bother with pq, del it in map
    //if it is edited, add the new edited task in pq while not bothering with
    //the old task values already in pq
    //whenever querying top from pq, check if that task is in map (map has
    //the latest status of everything) + check if the assigned priority and
    //user is correct then only it is the answer otherwise that is not the
    //latest state of that specific task (all taskID are unique)
    //so remove it from pq, do this removal until pq has a {task, user, priority}
    //that matches the latest state (that in map) -> return it + del from map
    unordered_map<int, pair<int, int>> m;//task, priority, user
    priority_queue<tuple<int, int, int>> pq;//priority, task, user
    TaskManager(vector<vector<int>>& tasks) {//given as user, task, priority
        for (auto& i : tasks) {
            pq.push({i[2], i[1], i[0]});
            m[i[1]] = {i[2], i[0]};
        }
    }
    
    void add(int u, int t, int p) {
        pq.push({p, t, u});
        m[t] = {p, u};
    }
    
    void edit(int t, int p) {
        pq.push({p, t, m[t].second});
        m[t].first = p;
    }
    
    void rmv(int t) {
        m.erase(t);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, t, u] = pq.top();
            //not in map or {priority, user} dont match
            if (m.find(t) == m.end() || p != m[t].first || u != m[t].second) {
                pq.pop();
            }
            else break;
        }
        if (pq.empty()) return -1;
        auto [p, t, u] = pq.top(); pq.pop();
        m.erase(t);
        return u;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */