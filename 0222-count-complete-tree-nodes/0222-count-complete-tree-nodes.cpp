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
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL) return 1;
        
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        
        while (!q.empty()){
            TreeNode* temp= q.front();
            q.pop();
            ans++;
            if (temp->left!=NULL) q.push(temp->left);
            if (temp->right!=NULL) q.push(temp->right);
        }
        return ans;
    }
};