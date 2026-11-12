class Solution {
public:
  string minimizeStringValue(string s) {
    int q = 0;
    vector<int> f(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      (s[i] == '?') ? q++ : f[s[i] - 'a']++;
    }
    //min heap <freq, char associated 1-26>, pq max size is 26
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //all the char freq pushed in
    for (int i = 0; i < 26; ++i) {
      pq.push({f[i], i});
    }
    //for all the ? marks increment freq of smallest freq chars 
    //so overall min cost can be obtained
    while (q--) {
      pair<int, int> p = pq.top(); pq.pop();
      pq.push({++p.first, p.second});//push with incremented freq
    }
    //now reuse freq[] and remove the freq of alr put chars in strings and store
    //the new freq which will help populate the string now (equal to num of ?)
    while (!pq.empty()) {
      int newFreq = pq.top().first - f[pq.top().second];//remove freq alr in string
      f[pq.top().second] = newFreq;
      pq.pop();
    }
    //now f[] 0->26 is lexicographical obv so take those freq put in place of ?s
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        while (!f[idx]) ++idx;
        s[i] = idx + 'a';
        --f[idx];
      }
    }
    return s;
  }
};