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
    int minSwaps(vector<int>& nums)
	{
	    int n = nums.size();
	    
	    // store the pair of {nums[i], i} in arr
	    
	    vector<pair<int, int>> arr(n);
	    
	    for(int i = 0; i < n; i++)
	    {
	        arr[i] = {nums[i], i};
	    }
	    
	    // sort the arr
	    
	    sort(arr.begin(), arr.end());
	    
	    int ans = 0;
	    
	    vector<bool> vis(n, false);
	    
	    for(int i = 0; i < n; i++)
	    {
	        // if curr number is at its correct position or number is already visted
	        
	        if(vis[i] || arr[i].second == i)
	        {
	            continue;
	        }
	        
	        // find the size of the cycle
	        
	        int j = i;
	        
	        int size = 0;
	        
	        while(vis[j] == false)
	        {
	            size++;
	            
	            vis[j] = true;
	            
	            j = arr[j].second;
	        }
	        
	        // update ans
	        
	        if(size > 1)
	        {
	            ans += size - 1;
	        }
	    }
	    
	    return ans;
	}
    
    
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        
        int ans=0;
        if (root->left!=NULL)q.push(root->left);
        if (root->right!=NULL)q.push(root->right);
        
        while (!q.empty()){
            vector<int> a(0,q.size());
            //vector<int> b(0,q.size());
            
            int g= q.size();
            for (int i=0;i<g;i++){
                TreeNode* temp = q.front();
                q.pop();
                a.push_back(temp->val);
            //    b.push_back(temp->val);
                
                if (temp->left!=NULL) q.push(temp->left );
                if (temp->right!=NULL) q.push(temp->right );
            }
            ans+= minSwaps(a);
        }
        return ans;
    }
};