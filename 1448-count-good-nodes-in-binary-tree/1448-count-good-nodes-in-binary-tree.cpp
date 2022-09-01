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
    int goodNodes(TreeNode* root) {
        int sol=0;
        travel(root,INT_MIN,sol);
        return sol;
    }
    
    void travel(TreeNode* node, int max_, int& ans){
        if (node==NULL) return;
        if (node->val>=max_) {ans=ans+1; cout << node->val << " is the good node" << max_ << " is max" << ans << " is count"<<endl; }
        max_ = max(node->val, max_);
        travel(node->left, max_, ans);
        travel(node->right,max_,ans);
    }
};