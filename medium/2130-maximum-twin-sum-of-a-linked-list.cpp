// 2130 - Maximum Twin Sum of a Linked List
// Difficulty: Medium
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // Étape 1 : Trouver le milieu avec la méthode du lièvre et de la tortue
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Étape 2 : Inverser la deuxième moitié de la liste
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Étape 3 : Calculer les sommes des paires et garder le max
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            maxSum = std::max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};