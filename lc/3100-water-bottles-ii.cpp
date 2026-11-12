class Solution {
public:
    int maxBottlesDrunk(int full, int exchange) {
        int drank = 0, empty = 0;
        while (full >= exchange) {
            drank += exchange;
            empty += exchange;
            full -= exchange;
            while (empty >= exchange) {
                empty -= exchange;
                ++exchange;
                ++full;
            }
        }
        return drank + full;
    }
};