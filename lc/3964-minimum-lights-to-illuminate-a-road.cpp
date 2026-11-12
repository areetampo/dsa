class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> iv(n + 1, 0); // line sweep
        for (int i = 0; i < n; i++) {
            int v = lights[i];
            if (v == 0) continue;
            iv[max(0, i - v)]++;
            iv[min(n, i + 1 + v)]--;
        }
        // i not illuminated means sum(iv[0...i+1]) = 0
        // these continous zeros must be illuminated
        // a position can light up adjacent pos = 3 pos from 1 bulb
        int res = 0, sweep = 0, zeros = 0;
        for (int i = 0; i < n; i++) {
            sweep += iv[i];
            if (sweep == 0) zeros++;
            else {
                res += zeros / 3 + (zeros % 3 != 0);
                zeros = 0;
            }
        }
        return res + zeros / 3 + (zeros % 3 != 0);
    }
};