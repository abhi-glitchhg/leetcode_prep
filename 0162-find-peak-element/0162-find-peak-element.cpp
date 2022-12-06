class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //find max element and its index with stl;
        
        int max_n = *max_element(nums.begin(), nums.end());
        return (int)(find(nums.begin(), nums.end(), max_n)-nums.begin());
    }
};