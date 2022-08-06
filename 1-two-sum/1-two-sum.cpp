class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // two pointer approach
        vector<int> sol ;
        
        vector<pair<int,int> > mapping;
        for (int i=0; i<nums.size();i++){
        mapping.push_back({nums[i],i});
        }
        
        int pointer1 = 0;
        int pointer2=  nums.size()-1;
        
        int n = sizeof(nums) / sizeof(nums[0]);
        
        sort(mapping.begin(),mapping.end());
        
        while (pointer2>pointer1){
            if (mapping[pointer1].first+mapping[pointer2].first>target){
                pointer2--;
            }
            else if (mapping[pointer1].first+mapping[pointer2].first<target){
                pointer1++;
            }
            else{
                
                sol.push_back(mapping[pointer1].second);
                sol.push_back(mapping[pointer2].second);
            
                break;
                
            }
        }
        
        
        return sol;
            
        
    }
        
};