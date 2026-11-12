class ProductOfNumbers {
public:
    vector<int> v = {1};
    void add(int a) {
        if (a > 0)
            v.push_back(v.back() * a);
        else
            v = {1};
    }

    int getProduct(int k) {
        return k >= v.size() ? 0 : v.back() / v[v.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */