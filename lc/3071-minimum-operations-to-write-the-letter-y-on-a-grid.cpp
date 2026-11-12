class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& g) {
        int n = g.size();
        int zy = 0, oy = 0, ty = 0, z = 0, o = 0, t = 0;//zero one two inside, outside y
        int i = -1, j = -1;
        while (i != n/2) {
            ++i; ++j;
            cout << i << " " << j << endl;
            if (!g[i][j]) ++zy;
            else if (g[i][j] == 1) ++oy;
            else ++ty;
            g[i][j] = -1;
        }
        i = -1; j = n;
        while (++i != --j) {
            cout << i << " " << j << endl;
            if (!g[i][j]) ++zy;
            else if (g[i][j] == 1) ++oy;
            else ++ty;
            g[i][j] = -1;
        }
        i = n/2; j = n/2;
        while (++i != n) {
                        cout << i << " " << j << endl;

            if (!g[i][j]) ++zy;
            else if (g[i][j] == 1) ++oy;
            else ++ty;
            g[i][j] = -1;
        }
        //now outside y
        i = 0; j = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == -1) continue;
                if (!g[i][j]) ++z;
                else if (g[i][j] == 1) ++o;
                else ++t;
            }
        }
        cout << z << " " << o << " " << t << " " << zy << " " << oy << " " << ty << endl;
        int a = z + oy;
        int b = z + ty;
        int c = o + zy;
        int d = o + ty;
        int e = t + zy;
        int f = t + oy;
        return n * n - max(max(max(a, b), max(c, d)), max(e, f));
    }
};