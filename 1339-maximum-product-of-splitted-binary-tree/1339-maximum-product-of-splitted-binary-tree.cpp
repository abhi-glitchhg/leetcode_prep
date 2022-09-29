
class Solution {
public:
    int mod=1e9+7;
    long long maxm;
    int total=0;
    int dfs(TreeNode* root)
    {
       if(!root) return 0;
        int curr=dfs(root->left)+dfs(root->right)+root->val;
        long long temp=curr*(long long)(total-curr);
        maxm=max(maxm,temp);
        return curr;

    }
    int maxProduct(TreeNode* root) {
        maxm=LLONG_MIN;
        total=dfs(root);
        dfs(root);
        return maxm%mod;
        
    }
};