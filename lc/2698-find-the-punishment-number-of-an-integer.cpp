class Solution {
public:
    bool can(int val, int target) {
        if (target == val)//if checking target == 0 && val == 0, fails at n = 1000
        //cuz there it ends at target = 1 and val = 1 where further breakdown: can(1/10, 1%10)
            return true;
        if (target * val <= 0)
            return false;
        return can(val / 10, target - (val % 10)) ||
               can(val / 100, target - (val % 100)) ||
               can(val / 1000, target - (val % 1000));
    }
    int punishmentNumber(int n) {
        int r = 0;
        for (int i = 1; i <= n; i++) {
            if (can(i * i, i))
                r += i * i;
        }
        return r;
    }
};