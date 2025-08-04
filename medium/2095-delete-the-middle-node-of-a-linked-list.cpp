// 2095-delete-the-middle-node-of-a-linked-list.cpp
// LeetCode 75 - Challenge C++
// Medium - Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

#include <iostream>
using namespace std;

// Définition du noeud de la liste chaînée (standard LeetCode)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Trouver le milieu avec la méthode des deux pointeurs
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Supprimer le noeud du milieu
        if (prev) prev->next = slow->next;
        return head;
    }
};