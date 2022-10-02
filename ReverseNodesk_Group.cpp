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
    ListNode *fun(ListNode *head,int k,int n)
    {
        if(n<k)return head;
        int c=0;
        ListNode*prev=NULL;
        ListNode *curr=head;
        while(curr && c<k)
        {
            c++;
            ListNode *t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        if(c==k && head)
        {
            head->next=fun(curr,k,n-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode *curr=head;
        while(curr)
        {
            n++;
            curr=curr->next;
        }

        return fun(head,k,n);
    }
};
