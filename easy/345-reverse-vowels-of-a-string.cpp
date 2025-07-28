// 345_reverse_vowels.cpp
// Solution for LeetCode problem 345 - Reverse Vowels of a String

#include <iostream>
#include <string>
#include <unordered_set>

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            while (left < right && vowels.find(s[left]) == vowels.end())
            {
                left++;
            }
            while (left < right && vowels.find(s[right]) == vowels.end())
            {
                right--;
            }
            if (left < right)
            {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

// Pour tester
// int main() {
//     Solution sol;
//     std::string input = "IceCreAm";
//     std::cout << sol.reverseVowels(input) << std::endl; // AceCreIm
//     return 0;
// }