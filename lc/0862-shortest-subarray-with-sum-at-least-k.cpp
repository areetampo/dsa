// ### Logic

// We use prefix sums + a monotonic increasing deque to find the shortest subarray with sum at least `k`.

// The deque stores `{prefix_sum, index}` pairs and maintains:

// - Left to right (front to back): strictly increasing prefix sums.
// - Indices are also increasing from front to back.

// There are two reasons to remove elements:

// 1\. Pop from front — consume valid candidates:

// For the current prefix sum `presum`, a previous prefix sum `P[j]` gives a valid subarray if:

// \\[ P[j] \leq presum-k \\]

// We calculate its length `i - j` and remove it. Any future subarray using the same `j` will be longer, so it cannot improve our answer.

// 2\. Pop from back — remove dominated candidates:

// &#x20;  If the current prefix sum is smaller than or equal to the last stored prefix sum, remove the latter.

// A smaller prefix sum at a later index is always better:

// - It makes the required sum condition easier to satisfy.
// - It produces a shorter subarray for any future endpoint.

// &#x20;  Therefore, the older, larger prefix sum is permanently useless.

// We initialize the deque with `{0, -1}` to account for subarrays starting at index `0`.

// Complexity: \\(O(n)\\) time and \\(O(n)\\) auxiliary space. Every element is inserted and removed at most once.

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {

        // Stores {prefix_sum, index}
        // Maintains strictly increasing prefix sums
        // from front (left) to back (right).
        deque<pair<long long, int>> dq;

        // Empty prefix: allows subarrays starting at index 0.
        dq.push_back({0, -1});

        long long presum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < a.size(); i++) {

            presum += a[i];

            // 1. Consume all valid previous prefix sums.
            // P[j] <= presum - k means the subarray sum >= k.
            while (!dq.empty() &&
                   dq.front().first <= presum - k) {

                ans = min(ans, i - dq.front().second);

                // This prefix sum cannot produce a better
                // answer at any future index.
                dq.pop_front();
            }

            // 2. Remove dominated prefix sums from the back.
            // Current prefix sum is smaller/equal and has
            // a higher index, so it is always a better candidate.
            while (!dq.empty() &&
                   dq.back().first >= presum) {

                dq.pop_back();
            }

            // 3. Insert current prefix sum.
            dq.push_back({presum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Remember the direction:

// ```
// FRONT (LEFT)                         BACK (RIGHT)
//      |                                    |
//      v                                    v
//   smallest prefix sum  ------------>  largest prefix sum

//        Increasing order  ------>
// ```

// - Front: check and consume valid candidates.
// - Back: remove dominated candidates.
// - Back: insert the current prefix sum.

// The key insight is that we're maintaining only non-dominated candidates, not simply sorting prefix sums.