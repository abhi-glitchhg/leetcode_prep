class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memoise(nums.size(),-1);
        return dp(nums, 0, memoise);
    }
    
    int dp(vector<int> &nums, int index, vector<int> &memoise){
        
        //either rob the current one 
        if (index >= nums.size()) return 0;
        if (memoise[index]!=-1) return memoise[index];
        int robbed = nums[index] + dp(nums, index+2, memoise);
        int not_robbed = dp(nums, index+1, memoise);
        return memoise[index]=max(robbed, not_robbed);
        
    }    
};