class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = nums.size();
        int ss =(int) a* (a+1)/2;
        int sol =0;
        for (int i:nums)
            sol+=i;
        return ss-sol;
    }
};