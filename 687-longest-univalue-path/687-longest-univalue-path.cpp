
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        vector<int> lens;
        dfs(root, lens);
      
        int max_= INT_MIN;
        for (auto i: lens)
            max_ = max(max_, i);
            
        return max_;
    }
    
    void dfs(TreeNode* head, vector<int>& lens){
        if (head == NULL) return;
        lens.push_back(travel(head, true, head->val));
        dfs(head->left, lens);
        dfs(head->right,lens);
        
    }
    
    
    int travel(TreeNode* head, bool is_head, int val){
        if (head==NULL) return 0;
        if (head->val != val) return 0;
        if (is_head) return   travel(head->left, false,val)+ travel(head->right,false, val);
        else return  1  + max(travel(head->left, false,val) , travel(head->right,false, val));
        return -1;
        
        
    }
};