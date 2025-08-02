// 735-asteroid-collision.cpp
// LeetCode 735 - Asteroid Collision
// Résolution du challenge LeetCode 75 en C++ par Josué Rocha

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int ast : asteroids) {
            bool destroyed = false;

            while (!stk.empty() && ast < 0 && stk.top() > 0) {
                if (stk.top() < -ast) {
                    stk.pop(); // explosion du dernier astéroïde positif
                    continue;
                } else if (stk.top() == -ast) {
                    stk.pop(); // les deux explosent
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                stk.push(ast);
            }
        }

        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; --i) {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
    }
};