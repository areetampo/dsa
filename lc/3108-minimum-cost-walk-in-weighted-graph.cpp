class Solution {
public:
    class DSU {
        int n;
        vector<int> par;
        vector<int> size;
    public:
        vector<int> mp;//& of wts in that component
        DSU(int n) {
            this->n = n;
            par.resize(n + 1);
            for (int i = 0; i <= n; i++) par[i] = i;
            size.resize(n + 1, 1);
            mp.resize(n + 1, -1);//all bits 1
        }
        int findPar(int x) {
            if (par[x] == x) return x;
            return par[x] = findPar(par[x]);
        }
        void unionBySize(int x, int y, int wt) {
            int parX = findPar(x);
            int parY = findPar(y);
            if (parX == parY) {
                mp[parX] &= wt;
                return;
            }
            if (size[parX] >= size[parY]) {
                par[parY] = parX;
                mp[parX] &= mp[parY] & wt;
                size[parX] += size[parY];
            }
            else {
                par[parX] = parY;
                mp[parY] &= mp[parX] & wt;
                size[parY] += size[parX];
            }
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        DSU d(n);
        for (auto e : E) {
            int a = e[0], b = e[1], wt = e[2];
            d.unionBySize(a, b, wt);
        }
        vector<int> res;
        for (auto q : Q) {
            int a = q[0], b = q[1];
            int parA = d.findPar(a), parB = d.findPar(b);
            res.push_back(parA == parB ? d.mp[parA] : -1);
        }
        return res;
    }
};