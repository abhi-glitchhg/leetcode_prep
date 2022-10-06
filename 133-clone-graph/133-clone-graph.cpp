/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return node;
       unordered_map<Node*, Node*> mapping;
        unordered_map<Node*, int> visited;
        
        dfs(node,mapping, visited);
        return mapping[node];
    }
    
    void dfs(Node* head, unordered_map<Node*, Node*>&mapping, unordered_map<Node*, int> &visited){
        if (head == NULL) return;
        if (visited[head] == 1) return;
        
        
        visited[head]=1;
        if (mapping[head]==NULL){
            Node* temp = new Node(head->val);
            mapping[head] = temp;}
            
            for (auto i: head->neighbors){
                if (mapping[i]==NULL){
                    Node* neigh = new Node(i->val);
                    mapping[i]=neigh;
                } 
                mapping[head]->neighbors.push_back(mapping[i]);
            }
        for (auto k: head->neighbors){
            //cout<< "K is now " << k->val <<" \n";
            dfs(k,mapping, visited);
        }
        
        
        
    }
};