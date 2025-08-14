# 790. Domino and Tromino Tiling

## 📝 Énoncé

On veut compter le nombre de façons de paver un plateau **2 × n** avec des **dominos (2×1)** et des **trominos** (en L), en autorisant les rotations. La réponse doit être donnée modulo **10^9 + 7**.

**Exemples :**

- n = 3 → 5
- n = 1 → 1

**Contraintes :** 1 ≤ n ≤ 1000

## 💡 Stratégie

**Idée directrice :** modéliser via **programmation dynamique** en exploitant une **récurrence compacte** qui évite de gérer explicitement les états “demi-colonnes”.

### Dérivation (intuition pédagogique)

Notons **F(n)** le nombre de pavages complets de **2×n**.

On peut montrer (par construction des derniers placements) que :

- soit on pose un **domino vertical** sur la dernière colonne → il reste un **2×(n-1)** : **F(n-1)**.
- soit on remplit les deux dernières colonnes avec **deux dominos horizontaux** → **F(n-2)**.
- soit on utilise **un tromino** qui “mord” sur la colonne précédente. En réalité, les configurations asymétriques se comptent proprement en introduisant un état “prolongement” **P(k)** (plateau 2×k avec un décalage d’une case). On obtient alors :
  - **F(n) = F(n-1) + F(n-2) + 2·P(n-1)**
  - **P(n) = F(n-2) + P(n-1)**  
  En éliminant **P**, on obtient la **récurrence compacte**:
  > **F(n) = 2·F(n-1) + F(n-3)**, pour **n ≥ 3**

**Conditions initiales** (vérifiables à la main) :

- **F(0)=1** (plateau vide, 1 façon par convention),
- **F(1)=1** (un domino vertical),
- **F(2)=2** (deux verticaux **ou** deux horizontaux).

### Implémentation

- Itérer de 3 à n en gardant seulement **F(n-1), F(n-2), F(n-3)** → **O(1)** mémoire.
- Modulo **M = 1e9+7**.

## 🧠 Complexité

- **Temps :** O(n)  
- **Espace :** O(1)

## ⚠️ Pièges à éviter

- Oublier les **cas de base** (n=1, n=2).
- Ne pas appliquer correctement le **modulo** après chaque addition/multiplication.
- Repartir de F(n-1)+F(n-2) seulement (insuffisant : il manque le terme **F(n-3)**).

## 💬 Ce que j’ai appris

- La présence des **trominos** impose un état “asymétrique” caché ; le **regroupement** dans une récurrence **F(n)=2F(n-1)+F(n-3)** simplifie drastiquement le code sans perdre la rigueur.
- Les **conditions initiales** bien choisies (F(0), F(1), F(2)) permettent une **implémentation O(1) espace**.

## ✅ Statut

Résolu — testé localement sur quelques cas, conforme aux exemples.
