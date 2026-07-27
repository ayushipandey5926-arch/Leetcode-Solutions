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
};