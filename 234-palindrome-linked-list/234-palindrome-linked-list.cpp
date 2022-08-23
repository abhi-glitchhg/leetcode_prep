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
    bool isPalindrome(ListNode* head) {
        
        stack<int> stack_obj; 
        if (!head->next) return head;
        ListNode* copyhead = head;
        stack_obj.push(head->val);
        head = head->next;
        while (head){
            stack_obj.push(head->val);
            head = head->next;
        }
        head = copyhead;
        while (!stack_obj.empty() && head){
            if (stack_obj.top() != head->val) return false;
            stack_obj.pop();
            head = head->next;
        }
        return true;
        
    }
};