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
    vector<int> lst;
    int f=0;
    travel(root, lst, f);
    for (int ff: lst)
        f+=ff;
    return f;
    }
    
    void travel(TreeNode* node,vector<int>& lst, int s){
        if (node == NULL)
            return ;
         s = s*10 +  node->val;
        if  ((node->left ==NULL) && (node->right == NULL))
            lst.push_back(s);
       
        //lst.push_back(node->val);
        travel(node->left,lst,s);
        travel(node->right, lst,s);
    }
    
};