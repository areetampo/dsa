class NumberContainers {
public:
    unordered_map<int, int> index_to_num;
    unordered_map<int, set<int>> num_indices;
    NumberContainers() {}
    
    void change(int index, int number) {
        if (index_to_num.count(index) == 1) {
            num_indices[index_to_num[index]].erase(index);
        }
        index_to_num[index] = number;
        num_indices[number].insert(index);
    }
    
    int find(int number) {
        return !num_indices[number].empty() ? *num_indices[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */