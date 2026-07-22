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
    ListNode* removeNodes(ListNode* head) {
        // Handle empty list to prevent crash
        if (head == NULL) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        
        ListNode* slow = prev;
        ListNode* fast = prev->next;
        while(fast != NULL){
            if(slow->val > fast->val){
                slow->next = fast->next;
                fast = slow->next;
            } else {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        ListNode* newNode = prev;
        ListNode* prev2 = NULL;
        while(newNode != NULL){  
            ListNode* f = newNode->next;
            newNode->next = prev2;
            prev2 = newNode;
            newNode = f;
        }
        return prev2;
    }
};