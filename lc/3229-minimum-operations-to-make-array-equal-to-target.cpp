class Solution {
public:
    //extention of 1526
    long long minimumOperations(vector<int>& x, vector<int>& y) {
        vector<int> d = {abs(y[0] - x[0])};
        //+ve / -ve seq separated by 0s
        for (int i = 1; i < x.size(); i++) {
            if (((long long)y[i] - x[i]) * (y[i - 1] - x[i - 1]) < 0) 
                d.push_back(0);
            d.push_back(abs(y[i] - x[i]));
        }
        // for (int &i : d) cout << i << " "; cout << "\n";
        long long res = 0; int n = d.size(), last = 0;
        //mountain seq start and end points are i and j
        for (int i = 0; i < n; ) {
            while (i < n && d[i] == 0) i++;
            if (i == n) break;
            int j = i;
            while (j + 1 < n && d[j] <= d[j + 1] && d[j] > 0) j++;
            res += abs(d[j]) - last;//peak of mountain seq - last el prev seq
            while (j + 1 < n && d[j] >= d[j + 1] && d[j] > 0) j++;
            // cout << d[i] << " " << d[j] << " " << last << " " << res << "\n";
            last = d[j];
            i = j + 1;
        }
        return res;
    }
};