class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> m; int curr = 0, res = 0;
        m[0].push_back(-1);
        for (int i = 0; i < arr.size(); i++) {
            curr ^= arr[i];
            if (m.find(curr) != m.end()) {
                cout << endl << i << ". ";
                for (int j : m[curr]) {
                    cout << j << " ";
                    //j + 1 to i total xor = 0
                    //j + 1 < i cuz (=) only possible when i th is 0 and all arr elements > 0
                    int len = i - j;// > 1
                    res += len - 1;
                }
            }
            m[curr].push_back(i);
        }
        return res;
    }
};