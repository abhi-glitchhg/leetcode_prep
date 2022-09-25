class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> gg;
        //for (auto i: nums1)
        //    gg[i]++;
        //for (auto i: nums2)
         //   gg[i]++;
        //sort gg wrt values
        //
        for (auto k:nums2)
            nums1.push_back(k);
        sort(nums1.begin(),nums1.end());
        double sol;
        if (nums1.size()%2 ==0) 
             sol =((double)nums1[nums1.size()/2] + nums1[nums1.size()/2 -1] )/2;
        else 
             sol = nums1[nums1.size()/2];
        
        
        //
        return sol;
    }
};