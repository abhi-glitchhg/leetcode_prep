for follow up; people have solved the question like this :
```cpp
class Solution {
public:
bool isPalindrome(ListNode* head) {
ListNode* slow = head;
ListNode* fast = head;
while (fast != NULL && fast->next != NULL) {
slow = slow->next;
fast = fast->next->next;
}
ListNode* previous = NULL;
while (slow != NULL) {
ListNode* temp = slow->next;
slow->next = previous;
previous = slow;
slow = temp;
}
ListNode* tail = previous;
while (tail != NULL && head != NULL) {
if (head->val != tail->val) {
return false;
}
head = head->next;
tail = tail->next;
}
return true;
}
};
​
```