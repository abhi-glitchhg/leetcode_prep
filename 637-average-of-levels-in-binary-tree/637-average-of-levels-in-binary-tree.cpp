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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sol;
        if (root == NULL ) return sol;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            double s =0;
            double sie = q.size();
            for (int i=0; i<sie;i++){
                TreeNode* temp = q.front();
                s +=temp->val;
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            //cout << s << " " << sie<<endl;
            sol.push_back((double)s/sie);
            
        }
        return sol;
        
        
    }
    
    
};