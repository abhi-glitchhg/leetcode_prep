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
    bool bal =true;
public:
    bool isBalanced(TreeNode* root) {
        int h = heightCalculator(root);
        
        if (h==-1)
            return false;
        return true;
    }
    
    int heightCalculator(TreeNode* root){
    if (root==NULL)
            return true;
    int l = heightCalculator(root->left);
    int r = heightCalculator(root->right);
    if(l==-1 or r==-1)
        return -1;
    if(abs(l-r)>1)
        return -1;
    return 1+max(l,r);
}
};