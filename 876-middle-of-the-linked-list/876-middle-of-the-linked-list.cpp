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
    ListNode* middleNode(ListNode* head) {
        if (! head->next) return head;
        else if (! head->next->next) return head->next;
        ListNode * middle = head;
        head = head->next;
        int i = 0;
        while (head){
            head=head->next;
            i+=1;
            if ( i%2 == 1)
                middle = middle->next;
        }
        return middle;
        
    }
};