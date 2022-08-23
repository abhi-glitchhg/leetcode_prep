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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* node = new ListNode();
        ListNode* copynode = node;
        while (list1 && list2){
            int val_to_be_passed = min(list1->val, list2->val);
            ListNode * list = new ListNode();
            list->val = val_to_be_passed;
            node->next = list;
            node= node->next;
            if (val_to_be_passed == list1->val)
                list1 = list1->next;
            else
                list2 = list2->next;
        }
        if (!list1){ 
            node->next = list2;
        }
        else if (!list2){ 
            node->next = list1;
        }
        return copynode->next;
    }
};