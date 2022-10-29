class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> canbevisited(nums.size(), INT_MAX);        
        dp(0,0,canbevisited,nums);
        return canbevisited[nums.size()-1];
    }
    
    void dp(int index, int num_jumps, vector<int> &canbevisited, vector<int> &nums){
        if (index>=canbevisited.size()) return;
        if (canbevisited[index] > num_jumps){
            canbevisited[index]=num_jumps;
            for (int j=index+nums[index];j>index;j--)
                dp(j, 1+num_jumps,canbevisited, nums);
            
        }
        return;
    }
};