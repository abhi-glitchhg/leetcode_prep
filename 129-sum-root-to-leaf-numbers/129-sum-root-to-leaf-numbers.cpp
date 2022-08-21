/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    vector<string> lst;
    int f=0;
    string ff ; 
    travel(root, lst, ff);
    
    for (string s:lst ){
        int temp = stoi(s);
        f+=temp;
    }
    return f;
    }
    
    void travel(TreeNode* node,vector<string>& lst, string s){
        if (node == NULL)
            return ;
        char ch =  node->val+'0';
         s = s + ch;
        if  ((node->left ==NULL) && (node->right == NULL))
            lst.push_back(s);
       
        //lst.push_back(node->val);
        travel(node->left,lst,s);
        travel(node->right, lst,s);
    }
    
};