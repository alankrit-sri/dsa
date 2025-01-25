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
    ListNode* deleteMiddle(ListNode* head) {
       if(head == NULL || head->next == NULL)
          return NULL;
       ListNode *fastPtr = head, *slowPtr = head, *prevSlowPtr = head;
       while(fastPtr != NULL && fastPtr->next != NULL)
       {
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;    
            fastPtr = fastPtr->next->next;
       }
        prevSlowPtr->next = slowPtr->next;
       return head;
    }
};
