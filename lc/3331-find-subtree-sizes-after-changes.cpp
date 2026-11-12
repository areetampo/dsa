class Solution {
public:
    void dfs(int curr, string& s, vector<int>& seen, vector<int>& p, vector<vector<int>>& g) {
  // dbg(curr); dbg(seen);
  char ch = s[curr];
  // dbg(ch);
  int closestAncestorWithSameChar = seen[ch - 97];
  if (closestAncestorWithSameChar != -1) p[curr] = closestAncestorWithSameChar;
  seen[ch - 97] = curr;//update to latest ancestor with same char
  for (int child : g[curr]) dfs(child, s, seen, p, g);
  seen[ch - 97] = closestAncestorWithSameChar;//revert back the char to previous ancestor
}
int subtreeSize(int curr, vector<vector<int>>& g, vector<int>& res) {
  int sum = 0;
  for (int child : g[curr]) {
    sum += subtreeSize(child, g, res);
  }
  return res[curr] = sum + 1;
}
vector<int> findSubtreeSizes(vector<int>& p, string s) {
  int n = p.size(), root;
  vector<vector<int>> g(n, vector<int>());//children of each node
  for (int i = 0; i < n; i++) {
    int par = p[i], child = i;
    if (par == -1) root = i;
    else g[par].push_back(child);
  }
//   dbg(g);
  //perform dfs to update each node's par in p vector to closest same ancestor in s
  vector<int> seen(26, -1);//which closest ancestor had the same char value
  dfs(root, s, seen, p, g);
//   dbg(p);
  //now p[i] contians i'th node's closest ancestor with same char
  //group together same all i with same p[i] values (i is the child and p[i] is th e parent) and put in res
  //the above 2 comments are wrong since eg:
  //p = [-1, 0, 0, 1, 1, 1]
  //      0  1  2  3  4  5 indices
  //so par of 3,4,5 is 1 so res[1] = 3 but 0 is par of 1 so p[0] = 1 but 3,4,5 should also be considered since subtree
  //so approach is to create graph again with updated p arr and perform dfs to get subtree sizes
  g = vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < n; i++) {
    int par = p[i], child = i;
    if (par != -1) g[par].push_back(child);
  }
//   dbg(g);
  vector<int> res(n, 0);
  subtreeSize(root, g, res);
//   dbg(res);
  return res;
}
};