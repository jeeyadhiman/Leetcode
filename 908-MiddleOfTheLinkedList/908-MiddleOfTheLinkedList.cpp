// Last updated: 6/4/2026, 5:43:16 PM
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp= head;
        int count=0;
        int cnt=1;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        count=count/2 +1;
        while(cnt!=count){
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
};