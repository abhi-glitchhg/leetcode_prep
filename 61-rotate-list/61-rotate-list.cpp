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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        
        vector<int> a;
        ListNode* ogHead = head;
        while(head!= NULL){
            a.push_back(head->val);
            head = head->next;
        }
        int n= a.size();
        k = k % n;
        head= ogHead;
        for (int i =n-k;i<n;i++){
            head->val = a[i];
            head=head->next;
        }
         
        for(int i=0;i<n-k;i++){
            head->val = a[i];
            head=head->next;
        }
        return ogHead;
    }
};