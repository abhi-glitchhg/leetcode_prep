class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> a;
        for (auto i:nums){
            if (a[i]!=0) return i;
            a[i]++;
        }
        return -1;
        
    }
};