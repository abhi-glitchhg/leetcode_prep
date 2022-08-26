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
    int kthSmallest(TreeNode* root, int k) {
      int h = k;
      vector<int> lst;
      travel(root, k,lst );
     return lst[0];   
    }
    void travel(TreeNode* node,int& k, vector<int>& lst){
        if (!lst.empty()) return ;
        if  (node == NULL) return ;
        travel(node->left,k,lst);
        k--;
        if (k==0) lst.push_back(node->val);
        travel(node->right,k, lst);
    }
};