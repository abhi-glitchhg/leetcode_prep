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
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        
        dfs(root, ans);
        return ans;
    }
    
    
    pair<int, int> dfs(TreeNode* root, int &ans){
        
        if (root==NULL) return {INT_MAX,INT_MIN};
        
        if (root->left==NULL && root->right==NULL) return {root->val, root->val};
        
        pair<int,int> p1 = dfs(root->left, ans);
        pair<int,int> p2 = dfs(root->right, ans);
        
        int min_ = min(p1.first, p2.first);
        int max_ = max(p2.second,p1.second);
        ans = max(ans, max ( abs(max_-root->val), abs(min_ -root->val)));
        return {min(min_, root->val), max(max_, root->val)};
    }
};