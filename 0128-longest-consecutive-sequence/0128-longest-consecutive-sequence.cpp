class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        
        for (int i=0;i<nums.size()-1; i++){
            nums[i]-= nums[i+1];
            nums[i]*=-1;
        }
        nums.erase(nums.end()-1);

        int ans=1;
        int curr=1;
        for (auto i: nums)
        {
            if (i==1)
                curr++;
            else if (i==0) continue;
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};