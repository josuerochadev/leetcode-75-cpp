# 714. Best Time to Buy and Sell Stock with Transaction Fee

## 📝 Énoncé

On vous donne un tableau `prices` où `prices[i]` est le prix d’une action le jour `i`, et un entier `fee` représentant les frais de transaction.  
Vous pouvez effectuer autant de transactions que vous le souhaitez (acheter + vendre), mais vous devez payer `fee` à chaque vente.  
Vous ne pouvez pas détenir plusieurs actions simultanément (il faut vendre avant de racheter).

### Exemple 1

Input: `prices = [1,3,2,8,4,9], fee = 2`  
Output: `8`  
Explication:  

- Acheter à 1, vendre à 8 → profit = (8 - 1 - 2) = 5  
- Acheter à 4, vendre à 9 → profit = (9 - 4 - 2) = 3  
Total = 8  

### Exemple 2

Input: `prices = [1,3,7,5,10,3], fee = 3`  
Output: `6`

---

## 💡 Stratégie

Utiliser une approche **programmation dynamique avec deux états** :  

- `hold` = profit maximum en tenant une action.  
- `cash` = profit maximum sans action en main.  

Formules de transition :  

- `hold = max(hold, cash - prices[i])` → soit on garde l’action, soit on en achète une.  
- `cash = max(cash, hold + prices[i] - fee)` → soit on garde notre cash, soit on vend une action et on paie la taxe.

Le résultat final est `cash` à la fin (on ne garde pas d’actions en portefeuille).

---

## 🧠 Complexité

- Temps : `O(n)` car on parcourt une fois la liste des prix.  
- Mémoire : `O(1)` car on n’utilise que deux variables (`hold` et `cash`).

---

## ⚠️ Pièges à éviter

- Ne pas oublier de **soustraire la taxe seulement lors de la vente** (et pas lors de l’achat).  
- Bien initialiser `hold = -prices[0]` (car acheter dès le premier jour est une option).  
- Ne pas confondre "acheter" et "tenir l’action".  

---

## 💬 Ce que j’ai appris

- La gestion de problème boursier revient souvent à alterner entre deux états : **cash vs hold**.  
- Les frais de transaction se gèrent simplement en les déduisant lors de la vente.  
- La DP peut être optimisée à O(1) mémoire dans beaucoup de problèmes financiers.

---

## ✅ Statut

✔️ Solution implémentée et validée
