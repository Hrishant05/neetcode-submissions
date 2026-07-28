/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Stratergy I need 3 datastructures to do this
        //map1 this will have <Node*, int> From og List Node pointers and their index values
        //vec1 this will have from list 1 <int, int> the <ind, random's ind>
        //vec2 this will have the new Node*

        if(head==nullptr) return nullptr;

        //Step 1 filling mp1 & Making basic new List
        map<Node*, int>mp1;
        Node* it = head;
        int cnt = 0;
        Node * newHead = new Node(head->val);
        Node* prev = newHead;
        while(it!=nullptr){
            mp1[it] = cnt;
            if(cnt!=0){
                Node* newNode =  new Node(it->val);
                prev->next = newNode;
                prev = newNode;
            }
            
            it = it->next;
            cnt++;
        }
        mp1[it] = cnt;

        //Step 2 - populating vector
        it = head;
        vector<int>vec1;
    
        while(it!=nullptr){
            int val = mp1[it->random];
            vec1.push_back(val);
            it = it->next;
        }

        //Step 3 - Populating vec2 - NEWLIST
        vector<Node *>vec2;
        it = newHead;
        while(it!=nullptr){
            vec2.push_back(it);
            it = it->next;
        }
        vec2.push_back(nullptr);

        //Step 4 - Final connecting random pointers
        it = newHead;
        cnt = 0;
        while(it!=nullptr){
            int ranInd = vec1[cnt];
            Node* randomPointer = vec2[ranInd];
            it->random = randomPointer;
            it = it->next;
            cnt++;
        }

        return newHead;
    }
};
