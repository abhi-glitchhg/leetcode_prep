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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* sol = head->next;
        ListNode* temp = NULL;
        ListNode* temp2 = new ListNode();
        while (head != NULL && head->next != NULL)
        {
            
            temp = head->next;
            head->next = head->next->next;
            temp->next= head;
            temp2->next = temp;
            temp2 = temp2->next->next;
            //cout << temp->val << temp->next->val<<endl;
            head = head->next;
            
            //delete temp;
        }
        return sol;
    }
};