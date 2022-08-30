/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> qq;
        vector<TreeNode*> pp;
        bool a = travel(root,p,pp);
        bool b =travel(root,q,qq);
        int mini=min(pp.size(),qq.size());
        //cout << a<<b<<mini<<endl;
        for (int i=0;i<mini-1;i++){
            if (pp[i+1]!=qq[i+1]) return pp[i];
        }
        /*for (TreeNode* a:pp)
            cout<< a->val<<endl;
        for (TreeNode* a:qq)
            cout<< a->val<<endl;
        cout <<mini<<" mini " ;
        */return pp[mini-1];
    }
    
    bool travel (TreeNode* head, TreeNode* p, vector<TreeNode*>& var){
        if (head == NULL ) return false;
        var.push_back(head);
        if (head->val == p->val)
            return true;
            
        if (travel(head->left,p,var) || travel(head->right,p,var)) return true;
        
        var.pop_back(); 
        return false;
    
    }
};