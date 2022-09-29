class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // easy level order traversal and choose the last element hahaha :)
        vector<int> ans;
        queue<TreeNode*> q;
        if (root == NULL) return ans;
        q.push(root);
        
        while (!q.empty()){
            TreeNode* temp;
            int gg = q.size();
            for (int i=0;i<gg;i++){
                temp = q.front();
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};