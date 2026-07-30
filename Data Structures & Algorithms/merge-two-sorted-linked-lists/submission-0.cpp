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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        ListNode* newHead;
        ListNode* prev;

        

        if(ptr1->val < ptr2->val){
            newHead = ptr1;
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            newHead = ptr2;
            prev = ptr2;
            ptr2 = ptr2->next;
        }


        while(ptr1 != nullptr && ptr2!=nullptr){
            if(ptr1->val < ptr2->val){
                prev->next = ptr1;
                prev = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                prev->next = ptr2;
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }

        while(ptr1!=nullptr){
            prev->next = ptr1;
            prev = ptr1;
            ptr1 = ptr1->next;
        }

        while(ptr2!=nullptr){
            prev->next = ptr2;
            prev = ptr2;
            ptr2 = ptr2->next;
        }

        return newHead;
    }
};
