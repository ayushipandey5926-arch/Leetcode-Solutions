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
        if(head==NULL) return NULL;

        for(Node* temp = head; temp!=NULL; temp = temp->next->next) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
        }

        for(Node* temp = head; temp!=NULL; temp = temp->next->next) {
            if(temp->random!=NULL) 
            temp->next->random = temp->random->next;
        }

        Node* dummy = new Node(-1);
        Node* copyTemp = dummy;
        for(Node* temp = head; temp!=NULL; temp = temp->next){
            copyTemp->next = temp->next;
            copyTemp = copyTemp->next;
            temp->next = temp->next->next;
        }
        return dummy->next;
    }
};