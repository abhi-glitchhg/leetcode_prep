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
    TreeNode* pruneTree(TreeNode* root) {
    travel(root);
    if (root->val==0 && root->left==NULL && root->right ==NULL) return NULL;
    return root;
    }
    
    void travel(TreeNode* head){
        
        //cout<< head->val<<" ";
        if  (head == NULL) return ;
        if (head->left == NULL && head->right== NULL) return;
        travel(head->left);
        
        if (head->left != NULL  ) { 
            if (head->left->val ==0 && head->left->left == NULL && head->left->right == NULL) {head->left = NULL; }}
        
        
        travel(head->right);
        
        
        if (head->right != NULL  ) { 
            if (head->right->val ==0 && head->right->left == NULL && head->right->right == NULL) {head->right = NULL;}}
        

        
    }
};