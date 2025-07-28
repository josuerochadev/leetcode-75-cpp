// 283-move-zeroes.cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0; // Position à laquelle insérer le prochain élément non nul

        // Première passe : déplacer les éléments non nuls à gauche
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[insertPos++] = nums[i];
            }
        }

        // Deuxième passe : remplir le reste avec des zéros
        while (insertPos < nums.size())
        {
            nums[insertPos++] = 0;
        }
    }
};