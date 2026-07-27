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
    ListNode* prev = NULL;
        while(head!=NULL) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
       /**vector<int> x;
       for(ListNode* temp = head; temp!=NULL; temp=temp->next) {
        x.push_back(temp->val);
       }
       
       int left = 0, right = x.size()-1;
       while(left<right) {
       if(x[left]!=x[right]) return false;
       left++;
       right--;
       }
       return true;
       */

       if (!head || !head->next) return true;

       ListNode* slow = head;
       ListNode* fast = head;
       while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        }


       ListNode* secondHalf = reverseList(slow->next);

       ListNode* L1 = head;
       ListNode* L2 = secondHalf;
       bool result = true;

       while(L2!=NULL) {
       if(L1->val != L2->val) {
       result = false;
       break;;
       }
       L1 = L1->next;
       L2 = L2->next;
       }
       return result;
    }

};