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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //stack<int> stack1;
        ListNode* node3 =new ListNode();
        ListNode* orig = node3;
        int carry = 0;
        while((l1 !=NULL) || (l2 !=NULL)){
            int to_add = 0;

            if (l1 == NULL)
                to_add = l2->val + carry;
            else if (l2 == NULL)
                to_add = l1->val+ carry;   
            else {
                to_add = l1->val + l2->val+ carry;}
            
                int to_add0 = to_add%10;
                ListNode* new_node = new ListNode(to_add0);
                node3->next = new_node;
                carry = (int)to_add/10;
                node3 = node3->next;
                if (l1!=NULL) l1=l1->next;
                if (l2!=NULL) l2=l2->next;
        }
        if (carry!=0) {
            ListNode* carry_ = new ListNode(carry);
            node3->next = carry_;
        }
        
        return orig->next;
    }
};