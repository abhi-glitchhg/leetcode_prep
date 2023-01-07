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
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        dfs(root,a);
        int point1 = 0;
        int point2 = a.size()-1;
        
        while (point2>point1){
            if (a[point1]+a[point2]==k) return true;
            else if (a[point1]+a[point2]>k)
                point2--;
            else point1++;    }
        return false;
    }
    void dfs(TreeNode* node, vector<int> &paths){
        if (node==NULL) return;
        dfs(node->left,paths);
        paths.push_back(node->val);
        dfs(node->right,paths);
        
        
    }
};