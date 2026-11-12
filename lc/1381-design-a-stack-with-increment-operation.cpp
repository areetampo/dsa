class CustomStack {
    vector<int> v, inc; int sz;
public:
    CustomStack(int maxSize) {
        sz = maxSize;
        v = vector<int>(), inc = vector<int>();
    }
    
    void push(int x) {
        if (v.size() < sz) v.push_back(x);
        while (inc.size() < v.size()) inc.push_back(0);
    }
    
    int pop() {
        if (v.empty()) return -1;
        int res = v.back() + inc.back();
        int x = inc.back();
        v.pop_back(); inc.pop_back();
        if (!inc.empty()) inc[inc.size() - 1] += x;
        return res;
    }
    
    void increment(int k, int val) {
        if (!inc.empty()) inc[min(k, (int)inc.size()) - 1] += val; 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */