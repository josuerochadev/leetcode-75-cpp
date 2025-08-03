// 933-number-of-recent-calls.cpp
// LeetCode 933 - Number of Recent Calls
// Difficulty: Easy
// https://leetcode.com/problems/number-of-recent-calls/

#include <queue>
using namespace std;

/**
 * Implémente un compteur de requêtes récentes sur une fenêtre glissante de 3000ms.
 */
class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};