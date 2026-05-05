class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        if (k == 0) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        
        return newHead;
    }
};