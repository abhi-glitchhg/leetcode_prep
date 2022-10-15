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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) return NULL;
        auto temp1=  head;
        auto temp2 = head->next->next;
        //auto temp3 = head;
        //int counter = 0;
        while (true){
            if (temp2==NULL) break;
            if (temp2->next == NULL) break;
            //cout << temp2->val <<" ";
            //temp3 = temp1;
            temp1=temp1->next;
            temp2 = temp2->next->next;
        }
        temp1->next = temp1->next->next;;
        
        return head;
    }
};