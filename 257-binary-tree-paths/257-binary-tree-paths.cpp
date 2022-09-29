
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root,"",ans);
        return ans;
        
        
    }
    
    void path(TreeNode* head,string path_s, vector<string> &ans){
        if (head==NULL) return ;
        if (path_s =="") path_s = to_string(head->val);
        else path_s = path_s+"->"+to_string(head->val);
        if (head->left ==NULL && head->right==NULL) ans.push_back(path_s);
        path(head->left, path_s, ans);
        path(head->right, path_s, ans);
        
        
        
    }
};