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
        bool b =travelwithpath(root, destValue,qq,path,-1);
        for (int i:pp)
        cout <<i<< " ";
        cout<<endl;
        for (int i:qq)
        cout <<i<< " ";
            int min_l = min(pp.size(), qq.size());
        
        
     if (find(pp.begin(), pp.end(), destValue) !=pp.end() || find(qq.begin(), qq.end(), startValue) != qq.end()) { 
         if (pp.size()> qq.size()) for (int i=0;i<pp.size() - qq.size();i++) sol+="U";
         else{
             reverse(path.begin(), path.end());
             //path.pop_back();
              //   reverse(path.begin(), path.end());
              for  (char a:path)
                 cout<<a<<endl;
             for (int i=0;i<qq.size()-pp.size();i++)
                 sol+=path[i];
             reverse(sol.begin(), sol.end());
         }
       }
        
    else{     
   // while (ppc<pp.size() && ppc<qq.size()){
   //     if (pp[ppc] ==qq[ppc]) ppc++;
   //     cout << pp[ppc] << qq[ppc]<<endl;
    //}
      //  cout << min_l<<endl;
    int g=0;
    for (int i=0;i<min_l-1;i++)
        if (pp[i+1]==qq[i+1])
            g+=1;
      //  for (int i:pp)
       // cout <<i<< " "<<g<<endl;
        
    //cout <<endl;
    //for (int i:qq)
      //  cout <<i<< " ";
    //cout <<endl;
    //cout <<"stay string bro"<< g<<" ";
    
    for (int i=g;i<pp.size()-1;i++)
        sol+="U";
    for (int i=g+1;i<qq.size();i++)
        sol+=path[i];
    }
        //for (char c: sol)
            //cout << c;
     return sol;   

    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool travel (TreeNode* head, int p, vector<int>& var){
        if (head == NULL ) return false;
        var.push_back(head->val);
        if (head->val == p)
            return true;
        
        if (travel(head->left,p,var) || travel(head->right,p,var)) return true;
        
        var.pop_back(); 
        return false;
    
    }
    
        bool travelwithpath (TreeNode* head, int p, vector<int>& var, vector<char>& path,char a){
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