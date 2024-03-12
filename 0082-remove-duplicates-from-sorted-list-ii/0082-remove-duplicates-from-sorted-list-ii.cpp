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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        stack<int>st;

        int lastElement = INT_MAX;

        while(temp!=NULL){
            if(!st.empty() && st.top()==temp->val){
                lastElement = st.top();
                st.pop();
                temp=temp->next;
            } else if(lastElement ==temp->val){
                temp=temp->next;
            } else{
                st.push(temp->val);
                temp=temp->next;
            }
        }

        ListNode *prev = NULL;
        while(!st.empty()){
            ListNode *newHead = new ListNode(st.top());
            st.pop();

            newHead->next = prev;
            prev = newHead;
        }
        return prev;
    }
};