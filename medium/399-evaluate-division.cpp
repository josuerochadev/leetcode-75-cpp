/**
 * LeetCode 399. Evaluate Division
 * Link: https://leetcode.com/problems/evaluate-division/
 * Level: Medium
 *
 * ✅ Idée clé
 * On modélise les équations comme un graphe orienté pondéré:
 *   - Pour a / b = v, on ajoute: a -> b (poids v) et b -> a (poids 1/v).
 * Répondre à C / D revient à chercher un chemin de C vers D et à multiplier les poids le long du chemin.
 *
 * 🧭 Approche
 * - Construction du graphe: O(E) où E = nb d'équations.
 * - Pour chaque requête, DFS (ou BFS) en multipliant les ratios.
 * - Cas particuliers:
 *   - Variables inconnues -> -1.0
 *   - C == D: retourner 1.0 uniquement si la variable existe dans le graphe (sinon -1.0).
 *
 * ⏱️ Complexité
 * - Construction: O(E)
 * - Par requête: O(V + E) dans le pire cas (petits inputs ici).
 *
 * 🧩 Reutilisable
 * - Helpers buildGraph(...) et dfs(...) isolés.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(
        const vector<vector<string>>& equations,
        const vector<double>& values,
        const vector<vector<string>>& queries
    ) {
        // 1) Construire le graphe
        unordered_map<string, vector<pair<string, double>>> g;
        g.reserve(equations.size() * 2);

        buildGraph(equations, values, g);

        // 2) Répondre aux requêtes
        vector<double> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            const string& src = q[0];
            const string& dst = q[1];

            // Si l'un des noeuds est inconnu, impossible d'évaluer
            if (!g.count(src) || !g.count(dst)) {
                // Cas particulier: x/x et x inconnu -> -1.0
                ans.push_back(-1.0);
                continue;
            }

            // Cas C == D: ratio 1.0 si la variable existe (garanti par le test ci-dessus)
            if (src == dst) {
                ans.push_back(1.0);
                continue;
            }

            // DFS avec accumulation des poids
            unordered_set<string> visited;
            double result = -1.0;
            if (dfs(src, dst, 1.0, g, visited, result)) {
                ans.push_back(result);
            } else {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }

private:
    // Construit un graphe orienté pondéré: a->b (v) et b->a (1/v)
    static void buildGraph(
        const vector<vector<string>>& equations,
        const vector<double>& values,
        unordered_map<string, vector<pair<string, double>>>& g
    ) {
        for (size_t i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double v = values[i];

            g[a].push_back({b, v});
            g[b].push_back({a, 1.0 / v});
        }
    }

    // DFS: cherche un chemin de 'u' à 'target', accumulant le produit 'acc'
    static bool dfs(
        const string& u,
        const string& target,
        double acc,
        const unordered_map<string, vector<pair<string, double>>>& g,
        unordered_set<string>& visited,
        double& out
    ) {
        if (u == target) {
            out = acc;
            return true;
        }
        if (visited.count(u)) return false;
        visited.insert(u);

        auto it = g.find(u);
        if (it == g.end()) return false;

        for (const auto& [v, w] : it->second) {
            if (!visited.count(v)) {
                if (dfs(v, target, acc * w, g, visited, out)) {
                    return true;
                }
            }
        }
        return false;
    }
};