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
        if(head == NULL)
             return head;
        if(n==0)
           return head;

        int length = 0;
        ListNode* curr=head;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        if(length == n){
            curr= head->next;
            return curr;

        }
        curr = head;
        int changeForm = length-n;
        int count = 1;
        while(count<changeForm && curr!= NULL){
            curr = curr->next;
            count++;
        }
        curr->next = curr->next->next;
        return head;

    }
};