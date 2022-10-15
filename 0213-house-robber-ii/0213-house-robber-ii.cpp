class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memoise1(nums.size(),-1);
        if (nums.size() ==1 ) return nums[0];        int one= 1;
        int zero = 0;
        vector<int> memoise2(nums.size(),-1);
        //int if_first = 0;
        int a = dp(nums, 1, zero, memoise1); int b=  dp(nums, 0, one, memoise2);
  return max(a,b);
    }
    
    int dp(vector<int> &nums, int index, int &if_first, vector<int> &memoise){
        //cout<<index<<" " <<if_first<< " \n";
        //either rob the current one 
        if (index >= nums.size()-if_first  ) return 0;
        if (memoise[index]!=-1) return memoise[index];
        int robbed = nums[index] + dp(nums, index+2, if_first, memoise);
        int not_robbed = dp(nums,  index+1, if_first, memoise);
        return memoise[index]=max(robbed, not_robbed);
        
    }    
};