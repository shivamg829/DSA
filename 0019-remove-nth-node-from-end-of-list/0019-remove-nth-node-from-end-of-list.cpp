class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        if (first == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* second = head;

        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        ListNode* del = second->next;
        second->next = del->next;
        delete del;

        return head;
    }
};