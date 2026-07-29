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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevNode = dummy;

        while(true) {
            ListNode* kth = prevNode;
            for(int i=0; i<k && kth != NULL; i++) {
                kth = kth->next;
            } 
            if(kth == NULL) break;

            ListNode* nextNode = kth->next;
            ListNode* prev = nextNode;
            ListNode* curr = prevNode->next;

            while(curr!=nextNode) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = prevNode->next;
            prevNode->next = kth;
            prevNode = temp;
        }
        return dummy->next;
    }
};