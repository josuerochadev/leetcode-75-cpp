/*
 * LeetCode 875. Koko Eating Bananas
 * Level: Medium
 * Repo: leetcode-75-cpp
 * Path: /medium/875-koko-eating-bananas/875-koko-eating-bananas.cpp
 *
 * Pattern: Binary Search on Answer (feasibility check)
 *
 * Key idea:
 *  - We guess an eating speed k and check if Koko can finish within h hours.
 *  - The check is monotonic: if k works, any larger k also works -> binary search.
 *
 * Complexity:
 *  - Let n = piles.size(), M = max(piles).
 *  - Time: O(n * log M), Space: O(1).
 *
 * Notes:
 *  - Use 64-bit sums to avoid overflow when accumulating hours.
 *  - Ceil division trick: hours += (pile + k - 1) / k.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Edge cases are naturally handled by the binary search bounds below.
        long long maxPile = 0;
        long long total = 0;
        for (int x : piles) {
            maxPile = max<long long>(maxPile, x);
            total += x;
        }

        // Lower bound can be 1, but we can tighten it to ceil(total / h)
        // because she must eat all bananas in h hours.
        long long lo = max(1LL, (total + h - 1) / h);
        long long hi = maxPile; // eating faster than the largest pile is never required

        auto canFinish = [&](long long k) -> bool {
            // Compute hours needed at speed k
            long long hours = 0;
            for (int pile : piles) {
                // ceil(pile / k) without floating point
                hours += (pile + k - 1) / k;
                if (hours > h) return false; // early exit for performance
            }
            return hours <= h;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canFinish(mid)) {
                hi = mid; // feasible: try smaller speed
            } else {
                lo = mid + 1; // infeasible: need more speed
            }
        }
        return static_cast<int>(lo);
    }
};

// Optional local test harness (commented out for LeetCode submission)
/*
int main() {
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << Solution().minEatingSpeed(piles, h) << "\n"; // Expect 4
    return 0;
}
*/