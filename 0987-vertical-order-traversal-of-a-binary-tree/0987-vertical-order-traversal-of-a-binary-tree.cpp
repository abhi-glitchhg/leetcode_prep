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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>, vector<int>> g;
        dfs(root, g, 0,0);
        
    
        int beg ;
        int las;
        for (auto i:g)
        {
            beg = i.first.first; break;
        }
        for (auto i:g)
            las=i.first.first;
        
        vector<vector<int>> ans(las-beg+1);
        for (auto i: g)
        {
            vector<int> b = i.second;
            if (b.size()>1)
                sort(b.begin(),b.end());
            for (auto j: b)
                ans[i.first.first - beg].push_back(j);
        }
        return ans;
    }
    
    
    void dfs(TreeNode* head, map<pair<int,int>, vector<int>> &g, int i, int j){
        
        
        if (head==NULL) return;
        
        g[{j,i}].push_back(head->val);
        dfs(head->left, g,i+1, j-1);
        dfs(head->right, g, i+1, j+1);
    }
};