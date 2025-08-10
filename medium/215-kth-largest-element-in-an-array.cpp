/*
 * LeetCode 215. Kth Largest Element in an Array
 * Niveau: Medium
 * Lien: https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 * Approches classiques:
 *  - Min-heap de taille k: O(n log k), simple et robuste
 *  - Quickselect (Hoare): O(n) en moyenne, O(n^2) pire cas, in-place, pas de tri complet
 *
 * Ici: Quickselect itératif, pivot aléatoire, in-place, sans tri complet.
 * Raison: répond au "Can you solve it without sorting?" avec complexité moyenne optimale.
 *
 * Reuse: Ce squelette est réutilisable pour tout problème de sélection d'ordre-statistique.
 */

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // On veut le k-ième plus grand => index cible en tri croissant = n - k
        const int n = (int)nums.size();
        const int target = n - k;

        // Quickselect itératif (pour éviter la récursion)
        std::mt19937 rng(std::random_device{}());

        int left = 0, right = n - 1;
        while (left <= right) {
            int pivotIndex = std::uniform_int_distribution<int>(left, right)(rng);
            int newPivot = partition(nums, left, right, pivotIndex);
            if (newPivot == target) {
                return nums[newPivot];
            } else if (newPivot < target) {
                left = newPivot + 1;
            } else {
                right = newPivot - 1;
            }
        }
        // Par contrat, on ne devrait jamais arriver ici si 1 <= k <= n
        return -1;
    }

private:
    // Partition de Lomuto (simple et suffisante ici)
    // Place nums[pivotIndex] à sa position finale comme si le tableau était trié croissant
    // et renvoie cette position. Tous les éléments <= pivot sont à gauche, > pivot à droite.
    int partition(vector<int>& a, int left, int right, int pivotIndex) {
        int pivotVal = a[pivotIndex];
        std::swap(a[pivotIndex], a[right]); // déplacer le pivot à la fin
        int store = left;
        for (int i = left; i < right; ++i) {
            if (a[i] < pivotVal) {           // "<" pour construire un ordre croissant
                std::swap(a[store++], a[i]);
            }
        }
        std::swap(a[store], a[right]);       // pivot à sa place finale
        return store;
    }
};

/*
 // Notes d’usage local:
 // - Aucun main() requis pour LeetCode.
 // - Pour tester rapidement en local, décommentez:

int main() {
    Solution s;
    vector<int> nums1{3,2,1,5,6,4};
    cout << s.findKthLargest(nums1, 2) << "\n"; // attendu 5

    vector<int> nums2{3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(nums2, 4) << "\n"; // attendu 4
    return 0;
}
*/