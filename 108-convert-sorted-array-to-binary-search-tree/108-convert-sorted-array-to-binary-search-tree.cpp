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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end = nums.size();
        int half_size=  end/2;
        int start = 0;
        int to_start=0;
        //if (end%2 !=0)
        to_start=1;
        if(end==1){
            TreeNode* node = new TreeNode(nums[0]);
    
           // cout << "this is base condition :"<< nums[0]<<endl;
            return node;
            
            }
        
        
         else if (end == 2){
            
            
            
            TreeNode* node0 = new TreeNode(nums[0]);
            TreeNode* node = new TreeNode(nums[1],node0,NULL );
            return node;
        }
        
        
        else{
        auto first = nums.cbegin() ;
        auto first_end = nums.cbegin() + half_size;
        auto last = nums.cend();
            vector<int> beg(first,first_end);
            vector<int> las(first_end+to_start ,last);
            cout << "this is out first half of the inputs"<<endl;
            for (int i: beg)
                cout<<i<<" ";
            cout<<endl;
            cout<<"this is second half"<<endl;
            for (int i: las)
                cout<<i<<" ";
            cout<<endl;
            
            
            TreeNode* new_node = new TreeNode(nums[half_size], sortedArrayToBST(beg), sortedArrayToBST(las));
            return new_node;
        }
        
            
    
    }
};