class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int summ = 0;
        
        return travel(root, false );
        
    }
    
    int travel(TreeNode* head, bool is_left){
        if (head==NULL) return 0;
        
        if (is_left && head->left==NULL && head->right==NULL) return head->val;
        
        return travel(head->left,true)+travel(head->right,false);
        
        
    }
};