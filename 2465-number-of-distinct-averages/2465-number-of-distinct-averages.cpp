class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<int, int> gg;
        
        sort(nums.begin(),nums.end());
        
        while (nums.size()>0){
            
            int a= nums[0];
            int b= nums[nums.size()-1];
            nums.pop_back();nums.erase(nums.begin());
            gg[a+b]++;
        }
        return gg.size();
    }
};