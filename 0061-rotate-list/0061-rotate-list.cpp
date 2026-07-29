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
    ListNode* y = head;
    ListNode* prev = NULL;
    while(y != NULL) {
        ListNode* temp = y->next;
        y->next = prev;
        prev = y;
        y = temp;
    } 
    return prev;
}

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

    int count = 1;
    ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    k = k % count;
    if(k == 0) return head;

    
    ListNode* splitPrev = head;
    for(int i = 1; i < count - k; i++) {
        splitPrev = splitPrev->next;
    }

    ListNode* L = splitPrev->next;   
    splitPrev->next = NULL;          

    ListNode* L1 = reverseList(head); 
    ListNode* L2 = reverseList(L);     

    head->next = L2;   

    ListNode* result = reverseList(L1);  
    return result;
    }
};