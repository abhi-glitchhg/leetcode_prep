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
    ListNode* reverseList(ListNode* head) {
        stack<int> stack_obj;
        ListNode* savelater =  new ListNode();
        if (!head) return head;
        else if (!head->next) return head;
        else {
            while (head){
                stack_obj.push(head->val);
                head = head->next;
            }
            ListNode * head = new ListNode();
            savelater = head;
            
            while (!stack_obj.empty()){
                int to_be_added = stack_obj.top() ;
                stack_obj.pop();
                //cout<< to_be_added <<" ";
              ListNode * list = new ListNode();
            list->val = to_be_added;
            head->next = list;
            head= head->next;
            }
        }
        return savelater->next;
    }
};