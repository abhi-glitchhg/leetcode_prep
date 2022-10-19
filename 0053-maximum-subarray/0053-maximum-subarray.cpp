class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max_current= nums[0] ;
        int max_running=nums[0];
        
        for (int i=1;i<nums.size();i++){
            max_running= max(max_running+nums[i], nums[i]);
            
            if (max_current<max_running)
                max_current=max_running;
            
        }
        return max_current;
    }
};

/*

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        max_l=nums[0]
        max_g=nums[0]
        
        for i in range(1,len(nums)):
            max_l =max(max_l+nums[i], nums[i])
            if max_l>max_g:
                max_g=max_l
        return max_g
        */