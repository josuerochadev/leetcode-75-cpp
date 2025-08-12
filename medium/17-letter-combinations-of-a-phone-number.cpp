/*
 * LeetCode 17. Letter Combinations of a Phone Number
 * URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Repository: leetcode-75-cpp
 * Path: medium/0017-letter-combinations-of-a-phone-number/0017-letter-combinations-of-a-phone-number.cpp
 *
 * Approach:
 * - Backtracking (DFS) sur les positions du string "digits".
 * - À chaque niveau, on itère sur les lettres mappées au chiffre courant et on construit la combinaison.
 * - Cas bord: si digits est vide -> renvoyer un vecteur vide (spécification LeetCode).
 *
 * Correctness:
 * - On explore exhaustivement le produit cartésien des lettres pour chaque chiffre, exactement une fois par combinaison.
 *
 * Complexity:
 * - Soit n = len(digits). Chaque chiffre a 3 ou 4 lettres -> O(3^n à 4^n) combinaisons.
 * - Temps: O(k^n), k ∈ {3,4}; Espace: O(n) pour la pile + O(#solutions) pour le résultat.
 *
 * Notes d’implémentation:
 * - Table de mapping indexée par chiffres '2'..'9'.
 * - Code sans dépendances non-standard, portable (iostream, vector, string).
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) return {}; // Respecte l’exemple 2 (retourner [])

        static const std::string map[10] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "bcd",  // 3  <-- ATTENTION: ceci serait faux ! (exemple pédagogique)
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        // ⚠ Correction du mapping juste en dessous. Je laisse le bloc ci-dessus
        // comme exemple de "piège" à éviter : un mapping incorrect casse tout.
        // On utilise donc la version correcte:

        static const std::string MAP[10] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        std::vector<std::string> out;
        std::string current;
        current.reserve(digits.size());

        // DFS récursif
        std::function<void(size_t)> dfs = [&](size_t idx) {
            if (idx == digits.size()) {
                out.push_back(current);
                return;
            }
            char d = digits[idx];
            const std::string& letters = MAP[d - '0'];
            for (char ch : letters) {
                current.push_back(ch);
                dfs(idx + 1);
                current.pop_back();
            }
        };

        dfs(0);
        return out;
    }
};

/* --- Petite main facultative pour test local rapide (à commenter si besoin) ---
int main() {
    Solution s;
    for (auto& t : {std::string("23"), std::string(""), std::string("2")} ) {
        auto ans = s.letterCombinations(t);
        std::cout << "digits=\"" << t << "\" -> [";
        for (size_t i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << (i + 1 < ans.size() ? ", " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
*/