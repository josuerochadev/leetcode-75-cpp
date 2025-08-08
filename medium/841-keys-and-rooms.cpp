// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/
// LeetCode 75 – Medium
// Résolu par Josué Xavier Rocha le 08/08/2025

#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        stack<int> toVisit;

        toVisit.push(0); // Commencer par la room 0

        while (!toVisit.empty()) {
            int current = toVisit.top();
            toVisit.pop();

            if (visited.count(current)) continue;

            visited.insert(current);

            for (int key : rooms[current]) {
                if (!visited.count(key)) {
                    toVisit.push(key);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};