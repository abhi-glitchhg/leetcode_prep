/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* copy_ = root;
        
        

        if (root == NULL) return root;
        queue<Node*> q1;
        q1.push(root);
        
        while(!q1.empty()){
            vector<Node*> v(q1.size());
            int size1 = q1.size();
            for (int i=0;i<size1; i++){ 
            Node* node = q1.front();
            q1.pop();
            if (node->left != NULL) q1.push(node->left);
            if (node->right != NULL) q1.push(node->right);
            v[i] = node;    
            }
            for (int jj=0; jj<v.size()-1;jj++){
                v[jj]->next = v[jj+1];
            }
            
        }
        return copy_;

        
    }
};