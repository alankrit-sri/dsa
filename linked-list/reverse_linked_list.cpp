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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* iter = head, *iterNext = NULL, *newHead = head;

        if(head == NULL)
            return head;
        
        iterNext = head->next;

        while(iter != NULL && iterNext != NULL)
        {
            if(iter == head)
            iter->next = NULL; // being the last node
        
            ListNode* temp = iterNext->next;
            iterNext->next = iter;
            iter = iterNext;
            iterNext = temp;
            newHead = iter;
        }
        return newHead;
    }
};
