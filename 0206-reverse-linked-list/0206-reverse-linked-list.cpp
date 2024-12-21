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
        ListNode* Prev=nullptr;
        ListNode* temp=head;

        while(temp!=nullptr){
            ListNode*front=temp->next;
            temp->next = Prev;
            Prev=temp;
            temp=front;
        }
        return Prev;
    }
};