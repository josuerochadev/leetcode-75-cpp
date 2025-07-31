// 724_find_pivot_index.cpp

#include <iostream>
#include <vector>
using namespace std;

// Fonction principale pour trouver le pivot index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Si le left sum == right sum, on a trouvé le pivot
            if (leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }

        return -1;
    }
};
