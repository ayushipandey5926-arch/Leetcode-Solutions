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
        if(head==NULL) return head;

        unordered_map<Node*, Node*> copyLL;

        for(Node* temp = head; temp!=NULL; temp = temp->next) {
            copyLL[temp] = new Node(temp->val);
        }

        for(Node* temp = head; temp!=NULL; temp = temp->next) {
            copyLL[temp]->next = copyLL[temp->next];
            copyLL[temp]->random = copyLL[temp->random];
        }
        return copyLL[head];
    }
};