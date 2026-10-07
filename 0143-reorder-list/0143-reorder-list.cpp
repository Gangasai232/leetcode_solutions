class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        slow->next = NULL;   // Split the list

        while (curr != NULL) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is now the head of reversed second half

        // 3. Merge the two halves alternately
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};