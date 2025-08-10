/*
 *  LeetCode 2542 — Maximum Subsequence Score
 *  Difficulty: Medium
 *
 *  Pattern: Sorting + Min-Heap (Top-K) + Running Sum
 *
 *  Key idea:
 *    - Coupler (nums2[i], nums1[i]), trier par nums2 en ordre décroissant.
 *    - Parcourir; on empile nums1[i] dans un min-heap pour garder les k plus grands
 *      et on maintient la somme courante des éléments présents dans le heap.
 *    - Dès que le heap atteint k éléments, la valeur actuelle de nums2 (triée décroissante)
 *      joue le rôle de minimum du sous-ensemble (car toutes les nums2 vues jusqu’ici ≥ actuelle).
 *      Score candidat = sum(nums1 sélectionnés) * nums2_courant.
 *    - Mettre à jour le maximum global.
 *
 *  Complexité:
 *    - Tri: O(n log n)
 *    - Parcours avec heap de taille ≤ k: O(n log k)
 *    => O(n log n) au global, mémoire O(k)
 *
 *  Pourquoi ça marche:
 *    - Fixer le minimum (via tri décroissant sur nums2) et maximiser la somme de nums1
 *      avec une sélection top-k (min-heap) est optimal : pour un minimum donné m,
 *      le score est m * (somme des k plus grands nums1 compatibles).
 *
 *  Reusable notes:
 *    - Utiliser long long pour les produits/sommes afin d’éviter les débordements.
 *    - Utiliser priority_queue<int, vector<int>, greater<int>> pour un min-heap en C++.
 */

#include <vector>
#include <queue>
#include <algorithm> // Ajouté pour std::sort
#include <functional> // Assure que std::greater est bien inclus
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = (int)nums1.size();
        vector<pair<int,int>> v; // (nums2, nums1)
        v.reserve(n);
        for (int i = 0; i < n; ++i) v.emplace_back(nums2[i], nums1[i]);

        // 1) Trier par nums2 décroissant
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            return a.first > b.first; // nums2 desc
        });

        // 2) Min-heap pour garder les k plus grands nums1, + somme courante
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long best = 0;

        for (const auto& [n2, n1] : v) {
            minHeap.push(n1);
            sum += n1;

            // Si on dépasse k, supprimer le plus petit nums1 pour rester top-k
            if ((int)minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // Quand on a k éléments, calculer score candidat
            if ((int)minHeap.size() == k) {
                long long candidate = sum * (long long)n2; // n2 est le min courant
                if (candidate > best) best = candidate;
            }
        }
        return best;
    }
};

/*
 *  Notes de test rapide (non requis par le repo):
 *
 *  Exemple 1:
 *    nums1=[1,3,3,2], nums2=[2,1,3,4], k=3 -> 12
 *  Exemple 2:
 *    nums1=[4,2,3,1,1], nums2=[7,5,10,9,6], k=1 -> 30
 *
 *  Compile (local):
 *    g++ -std=c++17 -O2 -Wall 2542-maximum-subsequence-score.cpp -o run
 */