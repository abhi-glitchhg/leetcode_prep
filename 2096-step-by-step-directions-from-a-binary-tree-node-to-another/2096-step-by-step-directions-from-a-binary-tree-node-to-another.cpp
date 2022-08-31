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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        vector<int> qq;
        vector<int> pp;
        string sol ="";
        vector<char> path;
        bool a = travel(root,startValue,pp);
        bool b =travelwithpath(root, destValue,qq,path,'_');

         int min_l = min(pp.size(), qq.size());
        
        
     if (find(pp.begin(), pp.end(), destValue) !=pp.end() || find(qq.begin(), qq.end(), startValue) != qq.end()) { //if one of the node is parent of the other then we will travel only in one direction, ie. only up or only down(i.e R and L)
         if (pp.size()> qq.size()) for (int i=0;i<pp.size() - qq.size();i++) sol+="U"; //this handles when the destVal is parent of startVal
         else{ // when startVal is parent of destVal
             reverse(path.begin(), path.end());
             for (int i=0;i<qq.size()-pp.size();i++)
                 sol+=path[i];
             reverse(sol.begin(), sol.end());
         }
       }
        
    else{     //none of the node are parent of each other; so we travel up till we find the first common ancestor and then we go down; in this down path we use the stored path in the travelwithpath function.
    int g=0;
    for (int i=0;i<min_l-1;i++)
        if (pp[i+1]==qq[i+1])
            g+=1;
    for (int i=g;i<pp.size()-1;i++)
        sol+="U";
    for (int i=g+1;i<qq.size();i++)
        sol+=path[i];
    }
     return sol;   
    }
    
    
    
    bool travel (TreeNode* head, int p, vector<int>& var){ // a travel function which stores the path of the node into variable var;
        if (head == NULL ) return false;
        var.push_back(head->val);
        if (head->val == p)
            return true;
        
        if (travel(head->left,p,var) || travel(head->right,p,var)) return true;
        
        var.pop_back(); 
        return false;
    
    }
    
        bool travelwithpath (TreeNode* head, int p, vector<int>& var, vector<char>& path,char a){ //same as travel but now we are storing if we are going left or right into path vector.
        if (head == NULL ) return false;
        path.push_back(a);
        var.push_back(head->val);
        if (head->val == p)
            return true;
        
        if (travelwithpath(head->left,p,var,path,'L') || travelwithpath(head->right,p,var,path,'R')) return true;
        
        var.pop_back(); 
        path.pop_back();
        return false;
    
    }
};