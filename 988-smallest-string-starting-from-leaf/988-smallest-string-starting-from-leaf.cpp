
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        path(root,"",ans);
        //return ans;
        
        sort(ans.begin(), ans.end());
        return ans[0];
    }
    
        
    void path(TreeNode* head,string path_s, vector<string> &ans){
        if (head==NULL) return ;
       
        path_s = (char) (head->val +'a')+path_s;
        if (head->left ==NULL && head->right==NULL) ans.push_back(path_s);
        path(head->left, path_s, ans);
        path(head->right, path_s, ans);
        
        
    }
};