/**
 * 2336. Smallest Number in Infinite Set
 * Level: Medium
 * URL: https://leetcode.com/problems/smallest-number-in-infinite-set/
 *
 * Design pattern:
 * - Pointer "next" for the natural stream 1,2,3,... (numbers never seen yet)
 * - Min-heap for "small numbers" re-inserted via addBack(num) when num < next
 * - Hash set to avoid duplicates in the heap
 *
 * Guarantees:
 * - popSmallest(): O(log k) where k = heap size (amortized)
 * - addBack(): O(log k) if pushed, O(1) otherwise
 *
 * Why this works:
 * - All integers >= next are implicitly present.
 * - Only numbers < next can be "missing" (popped earlier). We track those via a min-heap.
 */

#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class SmallestInfiniteSet {
private:
    // next = smallest integer that has never been popped yet
    int nextSmallest;

    // Min-heap for re-added numbers smaller than nextSmallest
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Fast membership check to prevent duplicates in the heap
    unordered_set<int> inHeap;

public:
    SmallestInfiniteSet() : nextSmallest(1) {}

    int popSmallest() {
        // If we have any re-added small numbers, they take priority
        if (!minHeap.empty()) {
            int x = minHeap.top();
            minHeap.pop();
            inHeap.erase(x);
            return x;
        }
        // Otherwise, consume the natural stream
        return nextSmallest++;
    }

    void addBack(int num) {
        // Only meaningful if num was previously popped:
        // That occurs iff num < nextSmallest.
        // Also avoid duplicates if it's already in the heap.
        if (num < nextSmallest && inHeap.find(num) == inHeap.end()) {
            minHeap.push(num);
            inHeap.insert(num);
        }
        // If num >= nextSmallest, it's already present implicitly: no-op.
    }
};

/*
 * Notes d’intégration:
 * - LeetCode attend uniquement la classe ci-dessus.
 * - Pas besoin de main(); les tests sont fournis par la plateforme.
 *
 * Sanity check mental:
 *   Start: next=1, heap={}
 *   pop -> 1 (next=2)
 *   pop -> 2 (next=3)
 *   addBack(1): 1 < next(3) => heap=[1]
 *   pop -> heap top => 1
 *   pop -> 3 (next=4)
 *   pop -> 4 (next=5)
 *
 * Everything consistent.
 */