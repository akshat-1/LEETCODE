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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)return head;
        stack<int> before;
        stack<int>after;

        ListNode* temp=head;

        while(temp != NULL)
        {
            if(temp->val < x)
            {
                before.push(temp->val);
                temp = temp->next;
            }
            else
            {
                after.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* p= NULL;
        ListNode* end = NULL;

        while(!before.empty())
        {
            ListNode* new_node = new ListNode(before.top());
            if(p == NULL) end = new_node;
            before.pop();
            new_node->next = p;
            p = new_node;
        }
    ListNode* q = NULL;
        while(!after.empty())
        {
            ListNode* new_node2 = new ListNode(after.top());
          
            after.pop();
            new_node2->next = q;
            q = new_node2; 
        }
        if(end!= NULL)
        end->next = q;
    if(p)
        return p;
    else return q;

        
    }
};