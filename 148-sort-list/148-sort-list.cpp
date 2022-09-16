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
    ListNode* sortList(ListNode* head) {
     vector<int> aa;
        ListNode* orig = head;
        while(head != NULL){
            aa.push_back(head->val);
            head=head->next;
        }
    sort(aa.begin(),aa.end());
        head = orig;
    for(auto i: aa){
        head->val = i;
        head=head->next;
    }
    return orig;
    }
};