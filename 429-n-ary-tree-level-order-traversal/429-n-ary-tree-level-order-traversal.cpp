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
class Solution {
public:
    vector<int> LevelOrder(Node* root) {
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
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> sol;
        if (root == NULL) return sol;
        queue<Node*> q1;
        q1.push(root);
        while(!q1.empty()){
            vector<int> v(q1.size());
            int size1 = q1.size();
            for (int i=0;i<size1; i++){ 
            Node* node = q1.front();
            //cout << node->val<< " ";
            q1.pop();
           // if (node->left != NULL) q1.push(node->left);
            //if (node->right != NULL) q1.push(node->right);
            for (Node* xyz:node->children)
                if (xyz != NULL )q1.push(xyz);
            v[i] = node->val;
            //cout << i << ' ';
            }
            sol.push_back(v);
        }
        return sol;
    }
};