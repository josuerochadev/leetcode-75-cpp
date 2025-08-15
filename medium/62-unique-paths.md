# 62. Unique Paths

## 📝 Énoncé

On a un robot dans une grille `m x n`, partant en haut à gauche (0,0) et allant en bas à droite (`m-1, n-1`). À chaque étape, il ne peut aller que **à droite** ou **en bas**.  
Retourner le **nombre de chemins uniques** possibles.  
`1 <= m, n <= 100`, et la réponse `<= 2 * 10^9`.

## 💡 Stratégie

**Formule combinatoire.**  
Un chemin de (0,0) à (m-1,n-1) contient exactement `(m-1)` déplacements **bas** et `(n-1)` déplacements **droite**, dans un ordre quelconque.  
Le nombre total d’ordres possibles = **combinaisons** de `(m+n-2)` mouvements en choisissant la position des `(m-1)` mouvements bas (ou `(n-1)` mouvements droite) :

\[
\text{Unique Paths} = \binom{m+n-2}{m-1} = \binom{m+n-2}{n-1}
\]

**Implémentation robuste**  
On calcule \(\binom{N}{K}\) en **O(min(m,n))** via la formule multiplicative :
\[
\binom{N}{K} = \prod_{i=1}^{K} \frac{N-K+i}{i}
\]
Cela évite les factorials et les surflows inutiles. On utilise `long long` et on divise à chaque itération (division exacte).

Alternative (DP):

- Table `dp[m][n]` avec `dp[i][j] = dp[i-1][j] + dp[i][j-1]` (bordures à 1).
- Complexité `O(mn)`, mémoire `O(n)` optimisable.  
Ici, la **combinatoire** est plus élégante et plus rapide.

## 🧠 Complexité

- Temps: `O(min(m, n))`  
- Espace: `O(1)`

## ⚠️ Pièges à éviter

- **Overflow** avec des factorials → préférer la formule multiplicative.
- **Mauvais cast**: travailler en `long long`, retourner `int` en fin (sûr car `<= 2e9`).
- **Ordre de calcul**: multiplier puis diviser à chaque pas pour rester sur des entiers exacts.

## 💬 Ce que j’ai appris

- Les chemins sur une grille avec déplacements bornés se modélisent naturellement par des **combinaisons**.
- La formule multiplicative est une **best practice** pour calculer `C(N, K)` sans gros entiers.

## ✅ Statut

Résolu ✅ – approche combinatoire + code propre.
