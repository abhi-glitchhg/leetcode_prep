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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> lst; 
        travel(root, lst);
        return lst;
    }
    
    void travel(TreeNode* node,vector<int>& lst){
        if  (node ==NULL) return ;
        travel(node->left,lst);
        lst.push_back(node->val);
        travel(node->right, lst);
    }
};
