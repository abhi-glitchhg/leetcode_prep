/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        copyList(head, mapping);
        return mapping[head];
    }
    
    void copyList(Node* node, unordered_map<Node*, Node*> &mapping){
        
        if (node==NULL) return;
        
        if (mapping[node]==NULL)
            mapping[node]=new Node(node->val);
        
        if (mapping[node->random]==NULL && node->random!= NULL)
            mapping[node->random] = new Node(node->random->val);
        
        if (mapping[node->next]==NULL && node->next!=NULL )
            mapping[node->next] = new Node (node->next->val);
        
        mapping[node]->next = mapping[node->next];
        mapping[node]->random= mapping[node->random];
        
        copyList(node->next, mapping);
        
        
        
    }
};