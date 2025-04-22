/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverseRecursive(ListNode* current, ListNode* prev) {
        if (!current) return prev;
        
        ListNode* nextNode = current->next;
        current->next = prev;
        
        return reverseRecursive(nextNode, current);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverseRecursive(head, nullptr);
    }
};
