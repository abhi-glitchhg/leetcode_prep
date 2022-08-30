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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int ans;
        
        while(!q1.empty()){
            //vector<int> v(q1.size());
            int size1 = q1.size();
            for (int i=0;i<size1; i++){ 
            TreeNode* node = q1.front();
            //cout << node->val<< " ";
            q1.pop();
            if (node->left != NULL) q1.push(node->left);
            if (node->right != NULL) q1.push(node->right);
            if (i==0) ans= node->val;
            //cout << i << ' ';
                    
            }
            
            
            
        }
        return ans;}
        
        

};