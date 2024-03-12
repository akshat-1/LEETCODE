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

    ListNode* merge( ListNode* head1 ,  ListNode* head2)
    {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        if(head2 == NULL)
        {
            return head1;
        }
        if(head1 == NULL)
        {
            return head2;
        }
        if(head1 == NULL && head2 == NULL)
        {
            return nullptr;
        }

        while(head1 && head2)
        {
                if(head1->val <= head2->val)
                {
                    head->next = head1;
                    head = head->next;

                    head1 = head1->next;
                }
                else
                {
                   head->next = head2;
                    head = head->next;

                    head2 = head2->next;
                } 
        }

        head->next = head1 ? head1:head2;        

        return temp->next;

        
    }

    ListNode* solve(vector<ListNode*>& lists , int start , int end )
    {   
        if(start == end)
        {
            return lists[start];
        }
        if(start+1 == end)
        {
            return merge(lists[start] , lists[end]);
        }

        int mid = start+ ( end-start)/2;
    ListNode* left = solve( lists , start , mid);
    ListNode* right = solve(lists, mid+1 , end);

    return merge(left ,right);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size() == 0)
        {
            return nullptr;
        }
        
       
        int start = 0;
        int end = lists.size()-1;

        return solve(lists, start , end);
    }
};