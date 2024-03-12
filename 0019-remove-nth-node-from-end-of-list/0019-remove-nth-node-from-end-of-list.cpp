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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 1;
        ListNode* tail  = head;
        ListNode* ptr = head;
         ListNode* ptr_prev = head;
        

        while(tail->next != NULL)
        {
            tail = tail->next;
            cnt++;
        }
        
    if(cnt != n)
    {
        for(int i=1;i<cnt-n+1 ; i++)
        {
            ptr = ptr->next;

        }

        for(int i=2;i<cnt-n+1 ; i++)
        {
            ptr_prev = ptr_prev->next;
            
        }

        ptr_prev->next = ptr->next;
        ptr->next = NULL;
        delete ptr;

        return head;
    }
    else{
        ListNode* temp = head;
        head = head->next;

        delete temp;

        return head;

    }
    }
};