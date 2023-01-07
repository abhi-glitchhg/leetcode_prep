class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> a;
        vector<int> ans;
        
        for(int i=1;i<nums.size()+1;i++)
            a[i]=0;
        for(auto i:nums)
            a[i]++;
        int twice=-1;int none=-1;
        //for (auto it:a)
        //    cout<< it.first<<" "<<it.second<<"\n";
        for (auto it: a)
        {        if (it.second==2)
                 twice = it.first;
                if (it.second==0)
                 none = it.first;
        }       
        ans.push_back(twice);
        ans.push_back(none);
        return ans;
        
    }
};