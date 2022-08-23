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
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* previous = NULL;
            while (slow != NULL) {
            ListNode* temp = slow->next;
            slow->next = previous;
            previous = slow;
            slow = temp;
            }   
            ListNode* tail = previous;
        
        int max_sum = INT_MIN;
        while (tail != NULL && head != NULL){ 
        max_sum = max(max_sum, head->val + tail->val);
        head = head->next;
        tail = tail->next;
        
        }
        return max_sum;
    
}
};