class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     vector<int> g(nums.size(),-1);
        for (int i= nums.size()-1; i>=0;i--)
            rec(i, nums,g);
        
        int ans =0;
        for (auto it:g)
        ans= max(ans,it);
        //cout<< it<<" ";}
            
        return ans+1;
        
    }
    
    
    int rec(int index, vector<int> &nums, vector<int> &g){
        if (index==0) return 0;
        int cur = nums[index];
        int og_index=index;
        if (g[index]!=-1) return g[index];
        int ans = 0;
        while (index>0){
            index--;
            if (nums[index]< cur)
                ans = max(ans,1+ rec(index, nums, g));
        }
        //if ()
        return g[og_index]=ans;
        
        
    }
};