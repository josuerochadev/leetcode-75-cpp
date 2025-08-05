// 0206-reverse-linked-list.cpp
// LeetCode 75 - 206. Reverse Linked List
// Niveau : Easy
// Lien : https://leetcode.com/problems/reverse-linked-list/
// Résolu le : 05/08/2025

#include <iostream>

// Définition de la structure de base pour les listes chaînées
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 🔁 Méthode 1 : Itérative
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* nextTemp = current->next; // Sauvegarde du suivant
        current->next = prev;               // Inversion du pointeur
        prev = current;                     // Avancer "prev"
        current = nextTemp;                 // Avancer "current"
    }

    return prev;
}

// 🔁 Méthode 2 : Récursive
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}