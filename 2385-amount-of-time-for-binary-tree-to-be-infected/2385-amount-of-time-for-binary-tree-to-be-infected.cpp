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
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> leanodepath;
        vector<int> current_path;
        bool a = travel(root, leanodepath, current_path);
    
        vector<int> target_path;
        bool b = travel_till_target_node(root, target_path, start); 
        vector<int> distances;
        
        for (auto i : leanodepath){ 
            bool break_flag= false;
            int j;
            for (j=0;j<target_path.size();j++){
                if (i[j] != target_path[j]) {break_flag= true; break;}
            }
                //cout<<j <<" "<<break_flag<<endl;

            if (break_flag) // not parent node
                distances.push_back(i.size()+target_path.size()-2*j+1);
            else 
                distances.push_back(i.size()-j+1);

            }
            
        
        
        int ans= INT_MIN;
        for (auto i: distances)
            ans= max(ans, i);
        //for (auto i: distances)
       //     cout<<i << " ";
        int target_size = target_path.size();
        //cout<<target_size ;
        ans = max(target_size, ans);
        return ans-1;
    
    }
    
    
        bool  travel(TreeNode* head, vector<vector<int>> &leafnodepaths, vector<int> &current_path ) { 
        if (head == NULL) return false;
        current_path.push_back(head->val);

        if (head->left == NULL && head->right==NULL) { leafnodepaths.push_back(current_path);}
        if (travel(head->left, leafnodepaths,current_path) || travel(head->right, leafnodepaths,current_path))
            return true;
        current_path.pop_back();
        return false;}
    
    
    
    
    
        
        bool  travel_till_target_node(TreeNode* head, vector<int> & paths, int  &target) { 
        if (head == NULL) return false;
        paths.push_back(head->val);

        if (head->val == target) return true;
        if (travel_till_target_node(head->left, paths, target) || travel_till_target_node(head->right, paths,target))
            return true;
        paths.pop_back();
        return false;}
};