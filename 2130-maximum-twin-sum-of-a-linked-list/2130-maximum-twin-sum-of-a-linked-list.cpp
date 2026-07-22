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
    int pairSum(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            } 
            ListNode* prev = NULL;
            ListNode* curr = slow;
            while(curr){
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            int maxVal = 0;
            while(prev){
                maxVal = max(maxVal, prev->val+head->val);
                prev=prev->next;
                head=head->next;
            }
        return maxVal;

    }
};