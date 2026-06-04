// Last updated: 6/4/2026, 5:43:33 PM
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
        ListNode* prev= nullptr;
        ListNode* curr=head;
        if(head==NULL) return head;
        ListNode* nextnode= head->next;
        while(nextnode!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            nextnode=nextnode->next;
        }
        curr->next=prev;
        head=curr;
        return head; 
    }
};