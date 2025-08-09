/*
 * 1926. Nearest Exit from Entrance in Maze
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 *
 * Pattern: BFS on grid (shortest path in unweighted graph)
 * Key idea: Multi-directional level-order traversal with in-place visited marking.
 *
 * Reusable notes:
 * - Use queue for BFS; push neighbors if they are inside bounds and walkable.
 * - Mark visited as soon as you enqueue to avoid duplicates.
 * - Distance is tracked by BFS layers (level by level).
 *
 * Time Complexity:  O(m * n)
 * Space Complexity: O(m * n) in worst case (queue/visited)
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int m = (int)maze.size();
        const int n = (int)maze[0].size();

        // Directions: down, up, right, left
        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        // BFS queue holds coordinates
        queue<pair<int,int>> q;

        // Start at entrance; mark it visited by converting '.' -> '+'
        int sr = entrance[0], sc = entrance[1];
        q.push({sr, sc});
        // Important: entrance is guaranteed to be empty ('.')
        maze[sr][sc] = '+';  // mark visited

        int steps = 0; // number of moves taken from entrance

        while (!q.empty()) {
            int layerSize = (int)q.size();
            // Process a full BFS layer; each layer represents 1 more step
            for (int i = 0; i < layerSize; ++i) {
                auto [r, c] = q.front(); q.pop();

                // Explore 4-neighbors
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // 1) Check bounds
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    // 2) Skip walls and visited cells (marked '+')
                    if (maze[nr][nc] != '.') continue;

                    // 3) If it's an empty cell, check if it's an exit (border cell)
                    //    Entrance itself doesn't count, but we never revisit it (already '+').
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        // We are moving from (r,c) to (nr,nc): this costs +1 step from current layer
                        return steps + 1;
                    }

                    // 4) Otherwise, enqueue and mark visited
                    maze[nr][nc] = '+'; // mark visited upon enqueue
                    q.push({nr, nc});
                }
            }
            // After processing current layer, we have taken one more step
            steps++;
        }

        // No exit reachable
        return -1;
    }
};