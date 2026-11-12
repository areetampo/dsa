class Solution {
public:
  int minimumDeletions(string word, int k) {
    int n = word.size();
    int res = INT_MAX;
    unordered_map<char, int> mp;
    for (auto it : word) mp[it]++;
    vector<int> v(26, 0);
    for (auto it : mp) {
      v.push_back(it.second);
    }
    sort(v.begin(), v.end());//brute force shit
    //assume each as min freq char left in end and all other chars adjusted according to
    //it to be <= k freq diff 
    for (int i : v) {
      int del = 0;
      for (int j : v) {
        if (i + k < j) {
          del += j - i - k;
        }
        else if (i > j) {//it will be the min freq char so higher freq ones directly del
          del += j;
        }
      }
      res = min(del, res);
    }
    return res;
  }
};