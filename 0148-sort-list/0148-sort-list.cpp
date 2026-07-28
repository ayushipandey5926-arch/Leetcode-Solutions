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

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        }
        return slow;
    } 

    ListNode* MergeList(ListNode* L1, ListNode* L2) {
        ListNode dummy = (0);
        ListNode* tail = &dummy;

        while(L1 && L2) {
            if(L1->val <= L2->val) {
                tail->next = L1;
                L1 = L1->next;
            } else {
                tail->next = L2;
                L2 = L2->next;
            }
            tail = tail->next;
        }

    
        tail->next = L1 ? L1 : L2;
        return dummy.next; 
    }


    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* rightL = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightL);

        return MergeList(left,right);
    }
};