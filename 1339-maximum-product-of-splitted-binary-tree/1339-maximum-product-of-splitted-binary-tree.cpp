class Solution {
public:
    int maxProduct(TreeNode* root) {
     int sol=0;
        unordered_map<TreeNode*, int> mapping;
         sol=dfs(root, mapping);
        queue<TreeNode*> q;
        long int a = INT_MIN;
        int total_sum = mapping[root];
        q.push(root);
        
        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left!=NULL) {
                q.push(temp->left); 
                if ( ((long int)(total_sum-mapping[temp->left])) * mapping[temp->left] > a) 
                    a = (long int)(total_sum-mapping[temp->left]) * mapping[temp->left];
                }
            if (temp->right!=NULL) {
                q.push(temp->right);
                if ( ((long int)(total_sum-mapping[temp->right])) * mapping[temp->right] > a) 
                    a = (long int)(total_sum-mapping[temp->right]) * mapping[temp->right];
            }
        }
        a %= 1000000007;
        return a;
        
        
    }
    
    int dfs(TreeNode* head, unordered_map<TreeNode* , int> &mapping){
        if (head==NULL) return 0;
        
       return mapping[head]= head->val + dfs(head->left,mapping) + dfs(head->right, mapping);
    }
};