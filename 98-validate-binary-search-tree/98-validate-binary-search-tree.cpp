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

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root->left ==NULL && root->right == NULL) return true;
        int bb=0;
        int aa=0;
        return isbinaryNode(root, LLONG_MAX, LLONG_MIN);
    }
    
    bool isbinaryNode(TreeNode* head, long long int max_, long long int min_ ){
        
        if (head == NULL) return true;
        
        int val = head->val;
        
        //if (val == INT_MAX) aa++; 
        //if (val == INT_MIN) bb++;
        //cout <<aa;
        /*
        if ((max_ <= val || val <=min_) && (val == INT_MIN || val == INT_MAX)){ 
            if (aa <2 && bb <2) 
                return ( isbinaryNode(head->left,min(max_ , val),min_ ,aa,bb) && isbinaryNode(head->right, max_, max(val, min_), aa,bb));
            else 
                return false;    
            }
        else if   ((max_ <= val || val <=min_)) return false;

        return ( isbinaryNode(head->left,min(max_ , val),min_ ) && isbinaryNode(head->right, max_, max(val, min_)));
        
    }
};*/


//above solution fails for edge cases otherwise works as a charm <3


class Solution {
public:
    vector<int> v;
    void inOrder(TreeNode* root){
        if(!root) return;
        
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
        return;
    }
        
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        inOrder(root);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]){
                flag=false;
                return flag;
            }
        }
        return flag;
    }
};