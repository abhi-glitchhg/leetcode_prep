/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> lst;
        if (root==NULL) return lst;
        lst.push_back(root->val);
        travel(root, lst);
        return lst;
    }
    
    void travel(Node* root, vector<int>& lst){
        if (root==NULL) return ;
        for (Node* a:root->children){
            lst.push_back(a->val);
            travel(a, lst);
        }
    }
};