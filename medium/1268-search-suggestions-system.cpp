/*
 * LeetCode 1268 — Search Suggestions System (Medium)
 * Repository: leetcode-75-cpp/medium
 * File: 1268-search-suggestions-system.cpp
 *
 * ✅ Approche principale: Tri + lower_bound (recherche binaire)
 * - On trie 'products' une seule fois (O(n log n)).
 * - Pour chaque préfixe de searchWord (1..L), on calcule l'itérateur de début via lower_bound.
 * - On collecte jusqu'à 3 produits qui commencent par le préfixe (vérification starts_with).
 *
 * Avantages:
 * - Simplicité et robustesse.
 * - Performances très compétitives pour les contraintes du problème.
 *
 * Complexité:
 * - Temps: O(n log n + L log n + K), avec
 *   n = nb de produits, L = longueur de searchWord,
 *   K ≈ n si on itère peu (mais on coupe à 3 éléments par préfixe).
 * - Espace: O(1) hors tri (ou O(n) si on considère la mémoire du tri).
 *
 * Alternatives:
 * - Trie (préfixes): O(sum(len(products))) en construction, O(L + 3*L) en requêtes.
 *   Plus verbeux et sans gain déterminant ici compte tenu des contraintes.
 *
 * Bonnes pratiques:
 * - Pas de 'using namespace std;'
 * - Helpers en fonctions libres, code commenté, signatures propres.
 * - Respect des normes C++17/C++20 usuelles pour LeetCode.
 */

#include <algorithm>
#include <string>
#include <vector>

namespace lc1268 {

static bool starts_with(const std::string& s, const std::string& prefix) {
    if (prefix.size() > s.size()) return false;
    // Comparaison caractère par caractère — sûre et lisible
    for (size_t i = 0; i < prefix.size(); ++i) {
        if (s[i] != prefix[i]) return false;
    }
    return true;
}

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, const std::string& searchWord) {
        // 1) Tri lexicographique des produits
        std::sort(products.begin(), products.end());

        std::vector<std::vector<std::string>> result;
        result.reserve(searchWord.size());

        std::string prefix;
        prefix.reserve(searchWord.size());

        // 2) Pour chaque caractère saisi => on étend le préfixe et on cherche la fenêtre
        auto it_begin = products.begin(); // optimisation: on ne repart pas du début à chaque fois

        for (char c : searchWord) {
            prefix.push_back(c);

            // lower_bound pour trouver le premier élément >= prefix
            it_begin = std::lower_bound(it_begin, products.end(), prefix);

            // Collecte jusqu'à 3 éléments qui matchent le préfixe
            std::vector<std::string> bucket;
            bucket.reserve(3);

            for (auto it = it_begin; it != products.end() && bucket.size() < 3; ++it) {
                if (starts_with(*it, prefix)) {
                    bucket.push_back(*it);
                } else {
                    // Dès que ça ne matche plus le préfixe, on peut sortir (car ordre lexicographique)
                    break;
                }
            }

            result.push_back(std::move(bucket));
        }

        return result;
    }
};

} // namespace lc1268

// --- Notes d’usage ---
// Sur LeetCode, coller uniquement la classe Solution (ajuster le namespace si nécessaire).
// Ici, le fichier est prêt pour être lu/maintenu dans ton repo.