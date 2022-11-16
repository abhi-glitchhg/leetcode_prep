class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<int, int> gg;
        
        sort(nums.begin(),nums.end());
        
        while (nums.size()>0){
            
            int a= nums[0];
             a+= nums[nums.size()-1];
            nums.pop_back();nums.erase(nums.begin());
            gg[a]++;
        }
        return gg.size();
    }
};