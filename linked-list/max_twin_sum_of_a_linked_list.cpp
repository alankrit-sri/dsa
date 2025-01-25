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
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(head == NULL)
            return head;
        
        ListNode* iter = head, *iterNext = head->next, *newHead = head;
        while(iter != NULL && iterNext != NULL)
        {
            ListNode *temp = iterNext->next;
            if(iter == head)
                iter->next = NULL;
            iterNext->next = iter;
            newHead = iterNext;
            iter = iterNext;
            iterNext = temp;
        }
        return newHead;
    }
    int pairSum(ListNode* head) {
        if(head == NULL)
            return 0;
        int maxPairSum = 0;
        ListNode *fastPtr = head, *slowPtr = head;
        while(fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            if(fastPtr != NULL)
            slowPtr = slowPtr->next;
        }
        ListNode *rightHalfHead = slowPtr->next;
        slowPtr->next = NULL;
        ListNode *leftHalfHead = reverseLinkedList(head);
        while(rightHalfHead != NULL)
        {
            maxPairSum = max(maxPairSum, (leftHalfHead->val + rightHalfHead->val));
            rightHalfHead = rightHalfHead->next;
            leftHalfHead = leftHalfHead->next;
        }
        return maxPairSum;
    }
};
