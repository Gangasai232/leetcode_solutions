class Solution {
    ListNode* function(ListNode* head, int len) {
        while (len--) {
            head = head->next;
        }
        return head;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0)
            return head;

        int cnt = 1;
        ListNode* temp = head;

        while (temp->next) {
            temp = temp->next;
            cnt++;
        }

        k %= cnt;
        if (k == 0)
            return head;

        temp->next = head;

        ListNode* lastNode = function(head, cnt - k - 1);

        head = lastNode->next;
        lastNode->next = nullptr;

        return head;
    }
};