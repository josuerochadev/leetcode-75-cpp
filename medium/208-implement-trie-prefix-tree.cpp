/*
===============================================================================
 LeetCode 208. Implement Trie (Prefix Tree)
 Difficulty: Medium
 Author: Josué (repo: leetcode-75-cpp)
 File: medium/208-implement-trie-prefix-tree.cpp
-------------------------------------------------------------------------------
 Pattern: Trie / Prefix Tree
 Key ops: insert, search, startsWith
 Complexity:
   - insert(word):  O(L)
   - search(word):  O(L)
   - startsWith(p): O(P)
 Where L = word.length, P = prefix.length
 Memory: O(total_chars) nodes * 26 children (lowercase a-z)
-------------------------------------------------------------------------------
 Notes:
 - Implémentation avec tableau fixe [26] pour perf/prédictibilité.
 - Destructeur pour free propre (pas de fuite mémoire).
 - API conforme LeetCode: class Trie { insert, search, startsWith }.
 - Bloc main() de test local désactivé (#ifdef LOCAL_TESTS).
===============================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    struct Node {
        // children[i] pointe vers la lettre 'a' + i, sinon nullptr
        Node* children[26];
        bool isEnd;
        Node() : isEnd(false) {
            // init pointeurs à nullptr
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };

    Node* root;

    // utilitaire pour libérer récursivement
    void freeNode(Node* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) freeNode(node->children[i]);
        }
        delete node;
    }

    // utilitaire pour naviguer jusqu'au noeud d'un mot/prefixe
    Node* traverse(const string& s) const {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26) return nullptr; // garde-fou (non requis sur LC)
            if (!cur->children[idx]) return nullptr;
            cur = cur->children[idx];
        }
        return cur;
    }

public:
    Trie() : root(new Node()) {}

    ~Trie() { freeNode(root); }

    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new Node();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    bool search(const string& word) const {
        Node* node = traverse(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(const string& prefix) const {
        return traverse(prefix) != nullptr;
    }
};

#ifdef LOCAL_TESTS
// Usage local: g++ -std=c++20 -DLOCAL_TESTS medium/208-implement-trie-prefix-tree.cpp && ./a.out
int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha
         << trie.search("apple") << "\n"     // true
         << trie.search("app") << "\n"       // false
         << trie.startsWith("app") << "\n";  // true
    trie.insert("app");
    cout << trie.search("app") << "\n";      // true
    return 0;
}
#endif