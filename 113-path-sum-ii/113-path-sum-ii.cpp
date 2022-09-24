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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentpath;
        travel(root, ans, targetSum, currentpath);
        return ans;
    }
    
    void travel(TreeNode* root, vector<vector<int>>& ans, int targetsum, vector<int> &currentpath){
        if (root==NULL) return;
        
        targetsum -= root->val;
        //if (targetsum<0) return;
        
        if (root->left == NULL && root->right == NULL)
        {
            if (targetsum==0){
                currentpath.push_back(root->val);
                ans.push_back(currentpath);
                return;
                
            }
            return;
        }
        
        else if (root->left!= NULL && root->right !=NULL){
            vector<int> rightpath = currentpath;
            rightpath.push_back(root->val);
            currentpath.push_back(root->val);
            
            travel(root->left, ans, targetsum, currentpath);
            travel(root->right, ans, targetsum, rightpath);
        }
        
        else if (root->left != NULL) {
            //if (targetsum<root->left->val)
            //    return;
            currentpath.push_back(root->val);
            travel(root->left, ans, targetsum, currentpath);
        }
        
        else if (root->right != NULL) {
            //if (targetsum<root->right->val)
            //    return;
            currentpath.push_back(root->val);
            travel(root->right, ans, targetsum, currentpath);
        }
            
    }
};