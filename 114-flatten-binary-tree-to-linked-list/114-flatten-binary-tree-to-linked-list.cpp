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
    void flatten(TreeNode* root) {
        vector<int> lst;
        travel(root, lst);
        treen(root, 0, lst);
        
    }
    void travel(TreeNode* node,vector<int>& lst){
        if  (node ==NULL) return ;
        lst.push_back(node->val);
        travel(node->left,lst);
        travel(node->right, lst);
    }
    
    void treen(TreeNode* node, int i, vector<int>& lst){
        if ((node == NULL) || i== lst.size())
            return ;
        node->val = lst[i];
        i++;
        node-> left = NULL;
        node->right = NULL;
        if (i!=lst.size()){ 
            TreeNode* node2 = new TreeNode(lst[i]);
            node->right = node2;
            treen(node2, i, lst);
        }
        
    }
};