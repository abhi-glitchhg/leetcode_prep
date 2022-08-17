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
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* p = root->left ;
        TreeNode* q = root->right ;
        
        
        if (!root) return true;
        
        return  isSameTree(p,q);        
        
    }
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (!p && !q){
            return true;
        }
        else if (!p || !q){
            return false;
        }
        else if (p->val != q->val ) return false;
        return isSameTree(p->right, q->left) && isSameTree(p->left, q->right);
    }
};