// 394-decode-string.cpp
// LeetCode 75 - 394. Decode String
// Résolution par Josué Rocha le 03/08/2025

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0'); // Gère les nombres à plusieurs chiffres
            } else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decoded = stringStack.top(); stringStack.pop();
                int currentK = countStack.top(); countStack.pop();
                while (currentK-- > 0) {
                    decoded += currentString;
                }
                currentString = decoded;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};