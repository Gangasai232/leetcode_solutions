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
    ListNode* reverselist(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newhead = reverselist(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;
        while(second){
            if(second->val != first->val){
                reverselist(newhead);
                return false;
            }
            second = second->next;
            first = first->next;
        }
        reverselist(newhead);
        return true;
    }
};