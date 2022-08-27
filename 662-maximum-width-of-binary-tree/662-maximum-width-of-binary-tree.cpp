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

//solution is copied from discussions but i understand what technique is used; very clever.
class Solution {
public:
   int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int minindex=INT_MAX,maxindex=INT_MIN;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top= q.front();
                q.pop();
                auto node= top.first;
                unsigned int index=top.second;
                minindex = min(minindex,(int)index);
                maxindex = max(maxindex,(int)index);
                if(node->left) q.push({node->left,2*index+1});
                if(node->right) q.push({node->right,2*index+2});
            }
            ans = max(maxindex-minindex+1,ans);
        }
        return ans;
    }
};