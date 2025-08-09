/*
 *  LeetCode 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *  Level: Medium
 *  Date: 2025-08-09 (Europe/Paris)
 *
 *  Problem:
 *    Given a tree of n nodes (0..n-1) with directed edges connections[i] = [a, b] meaning a -> b,
 *    find the minimum number of edges to reverse so every node can reach node 0.
 *
 *  Key idea (BFS safe-stack version):
 *    Build an undirected adjacency list, tagging each neighbor with a flag:
 *      - If original edge is u -> v, store (v, needsReverse=1) in adj[u].
 *      - Also store (u, needsReverse=0) in adj[v] (the reverse is naturally in the "good" direction).
 *    Then traverse from 0 (BFS). Every time we go to an unvisited neighbor:
 *      - If needsReverse == 1, we must reverse that edge to make it point towards the root (0). Count++.
 *    Sum of such flags visited exactly once is the minimal number of reorders.
 *
 *  Complexity:
 *    Time:  O(n)
 *    Space: O(n)
 *
 *  Notes:
 *    - Use BFS to avoid potential deep recursion (n up to 5e4).
 *    - Works because each original directed edge is assessed exactly once on the unique path to 0.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        adj.reserve(n);

        // Build tagged undirected graph
        for (const auto& e : connections) {
            int u = e[0], v = e[1];
            // Original direction u -> v needs reversal when moving from u towards 0
            adj[u].push_back({v, 1});
            // Opposite is already "towards 0" if needed
            adj[v].push_back({u, 0});
        }

        vector<char> seen(n, 0);
        queue<int> q;
        q.push(0);
        seen[0] = 1;

        int reversals = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (auto [nbr, needsReverse] : adj[cur]) {
                if (seen[nbr]) continue;
                // If edge cur -> nbr was originally oriented cur -> nbr (needsReverse=1),
                // and we're exploring away from 0, that means we must flip it to point towards cur.
                reversals += needsReverse;
                seen[nbr] = 1;
                q.push(nbr);
            }
        }

        return reversals;
    }
};

/*
 * Reusable runner (optional for local testing)
 *
 * Example:
 *   Input:
 *     n = 6
 *     connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
 *   Output: 3
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Minimal I/O harness (comment out when submitting on LeetCode which provides its own harness)
    // Format:
    // n
    // m (= n-1)
    // then m lines: a b
    int n;
    if (!(cin >> n)) return 0;
    int m = n - 1;
    vector<vector<int>> connections;
    connections.reserve(m);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        connections.push_back({a, b});
    }
    Solution s;
    cout << s.minReorder(n, connections) << "\n";
    return 0;
}