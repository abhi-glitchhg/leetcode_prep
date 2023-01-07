class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3) return false;
        vector<vector<int>> gg(nums.size()-2);
        
        int l_min= nums[0];
        for (int i=1; i<nums.size()-1;i++){
            gg[i-1].push_back(l_min);
            l_min = min(l_min, nums[i]);
        }
        
        int r_max = nums[nums.size()-1];
        for (int i=nums.size()-2; i>0;i--){
            gg[i-1].push_back(r_max);
            r_max = max(r_max, nums[i]);
        }
        int index=1;
        
        for (auto it:gg){
            if (nums[index]> it[0] && nums[index]<it[1])
                return true;
            index++;
        }
       /* for (auto it:gg){
            for (auto i:it)
                cout<<i<<" ";
            cout<<"\n";
        }*/
 
        return false;
        
    }
};