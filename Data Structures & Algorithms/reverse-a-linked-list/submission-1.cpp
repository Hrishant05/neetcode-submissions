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
        if(!head || !head->next){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextPtr;

        while(curr!=NULL){
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }
};
