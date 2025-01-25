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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode *temp = head, *evenEnd = head, *oddStart = NULL, *merge = NULL;
        int ind = 0;
        while(temp != NULL) {
            if(ind & 1) {
                if(oddStart == NULL)
                {
                    oddStart = temp;
                    merge = temp;
                }
                else
                {
                    oddStart->next = temp;
                    oddStart = oddStart->next;
                }
            }
            else
            {
                if(evenEnd != temp)
                {
                    evenEnd->next = temp;
                    evenEnd = evenEnd->next;
                }
            }
            ind++;
            temp = temp->next;
        }
        if(oddStart != NULL && evenEnd != NULL)
        {
            evenEnd->next = merge;
            oddStart->next = NULL;
        }
        return head;
    }
};
