class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        if(n == cnt) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        for(int i = 0; i < cnt - n - 1; i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};