class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0; int b=0;
        int temp_res=0;
        vector<int> sol;
        for (int i=0; i<nums.size();i++){
            temp_res ^= nums[i];
        }
        int lsb = 0;
        int index=0;
        while(not lsb){
            lsb = temp_res&1;
            temp_res = temp_res>>1;
            index++;
        }
        index--;
        int decider = 1 << index;
        
        for (int i=0; i<nums.size();i++){
            if (nums[i]&decider)
                a = a^nums[i];
            else
                b=b^nums[i];
                
        }
        sol.push_back(a);
        sol.push_back(b);
        return sol;
        
        
        
    }
};