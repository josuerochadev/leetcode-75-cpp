// 649. Dota2 Senate
// https://leetcode.com/problems/dota2-senate/
// Résolution dans le cadre du challenge LeetCode 75 en C++

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant;
        queue<int> dire;

        // On initialise les files d'attente avec les index des sénateurs
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        // Simulation des tours
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d) {
                radiant.push(r + n); // R bannit D et revient au prochain round
            } else {
                dire.push(d + n);    // D bannit R et revient au prochain round
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};