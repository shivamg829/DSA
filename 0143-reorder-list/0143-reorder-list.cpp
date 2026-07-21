class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Separate and reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Merge both halves
        ListNode* second = prev;
        ListNode* first = head;

        while (second != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};