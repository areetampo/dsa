class BrowserHistory {
private: 
    vector<string> sites;
    int curr;
public:
    BrowserHistory(string homepage) {
        sites = { homepage };
        curr = 0;
    }
    void visit(string url) {
        ++curr;
        sites.resize(curr);
        sites.push_back(url);
    }
    string back(int steps) {
        curr -= steps;
        if (curr < 0) curr = 0;
        return sites[curr];
    }
    string forward(int steps) {
        curr += steps;
        if (curr >= sites.size()) curr = sites.size() - 1;
        return sites[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */