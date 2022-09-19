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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
     int counter = 0;
        if (head->next == NULL) return NULL;
        ListNode* oghead =head;
        while (head!=NULL){
         head = head->next;
            counter++;
     }
        
        head = oghead;
        
        if (k == counter ) return head->next;
       while (counter!=k+1){
           head= head->next;
           counter--;
       }
        if (k == 1 ) head->next = NULL;
        else    head->next = head->next->next;
    return oghead;    
    }
    
};