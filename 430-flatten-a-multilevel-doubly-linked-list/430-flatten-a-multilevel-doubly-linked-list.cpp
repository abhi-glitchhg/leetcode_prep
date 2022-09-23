class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> aa;
        travel(head,aa);
        return head;
        // smile :)
}
    
    void travel(Node* head, stack<Node*> &aa){
        if (head == NULL) return;
        while (head->child == NULL && head->next != NULL)
            head = head->next;
        if (head->child != NULL && head->next == NULL){
            head->next = head->child;
            head->child = NULL;
            head->next->prev = head;
            travel(head->next, aa);
        }
        else if (head->child != NULL){ 
            aa.push(head->next);
            head->next = head->child;
            head->child = NULL;
            head->next->prev = head;
            travel(head->next, aa);
        }
        else  {
            if (aa.empty()) return ;
            head->next= aa.top();
            aa.top()->prev = head;
            aa.pop();
            travel(head->next,aa);
        }      
    }
};