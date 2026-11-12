class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        //all work simultaneously
        //if 4 cars and 1 worker with rank 10 -> 10 * 4 * 4 = 160 time
        //not 2-2 cars -> 10 * 2 * 2 + 10 * 2 * 2 = 80 time wrong
        //lowest rank = fastest worker
        //distribute the cars to minimze the maximum of ranks[i] * car * car
        long long lo = *min_element(ranks.begin(), ranks.end()), hi = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        //lo = lowest rank worker does 1 car, hi = lowest rank worked does all cars
        while (lo <= hi) {
            long long time = lo + (hi - lo) / 2;
            int c = cars;
            // cout << time << "\n";
            for (int &i : ranks) {
                //time = i * (some cars)^2 -> try to fit as many cars possible in given time
                // cout << (int)sqrt(time / i) << " ";
                c -= (int)sqrt(time / i);
                if (c <= 0) break;
            }
            // cout << "---\n";
            if (c <= 0) hi = time - 1;
            else lo = time + 1;
        }
        return lo;
    }
};