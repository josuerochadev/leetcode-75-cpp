# 11. Container With Most Water

## 📝 Énoncé
On vous donne un tableau `height` où chaque élément représente la hauteur d'une ligne verticale. Trouvez deux lignes qui, avec l'axe des abscisses, forment un récipient contenant la quantité maximale d'eau.

## 💡 Stratégie
Utiliser deux pointeurs pour tester toutes les paires possibles en O(n) :
- Commencer avec un pointeur au début et un autre à la fin.
- Calculer l'aire à chaque itération.
- Déplacer le pointeur qui pointe vers la ligne la plus courte.

## 🧠 Complexité
- Temps : O(n)
- Espace : O(1)

## ⚠️ Pièges à éviter
- Ne pas prendre le max entre les deux hauteurs, mais le **min**.
- Ne pas oublier de mettre à jour l’aire maximale.
- Ne pas confondre largeur et index.

## 💬 Ce que j’ai appris
- L’approche Two Pointers peut résoudre efficacement des problèmes de recherche maximale sur des intervalles.
- Optimiser un produit sous contrainte implique souvent de bouger intelligemment un curseur.

## ✅ Statut
Résolu ✅