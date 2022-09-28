class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> sol;
        int t_K=k;
        vector<TreeNode*> paths;
        bool a = travel(root, paths, target);
        reverse(paths.begin(), paths.end());
        
        for (int i=1; i<paths.size(); i++){
            TreeNode* temp = paths[i];
            k--;
            //if (k==1){search(temp, sol, k); break;}
            if (temp->right==paths[i-1]) temp = temp->left;
            else temp = temp->right;
            
            search(temp,sol, k-1);
        }
        search(target, sol,t_K);
        if (t_K < paths.size() && t_K !=0) sol.push_back(paths[t_K]->val);
//        cout <<paths[t_K]->val;
        return sol;
    }
    
    
    void search(TreeNode* head, vector<int>& sol, int k){
        if (k<0) return ;
        if (head == NULL )return ;
        if (k ==0) {sol.push_back(head->val);return ;}
        search( head->left, sol, k-1);
        search( head->right, sol, k-1);
        
    
    }
    
    bool  travel(TreeNode* head, vector<TreeNode*> & paths, TreeNode*  &target) { 
        if (head == NULL) return false;
        paths.push_back(head);

        if (head->val == target->val) return true;
        if (travel(head->left, paths, target) || travel(head->right, paths,target))
            return true;
        paths.pop_back();
        return false;}
};