class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_ = accumulate(nums.begin(), nums.end(),0);
        int sum_t = 0;
        
        if (nums[0] == sum_) return 0;
            
        for (int i=1;i<nums.size();i++){
            int nisum = sum_ - nums[i];
            sum_t +=nums[i-1];
            if (2*sum_t == nisum) return i;
        }
        return -1;
    }
};