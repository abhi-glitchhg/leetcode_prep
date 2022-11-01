class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end());
        //for(auto i: intervals)
         //   cout<<i[0]<<" "<<i[1]<<"\n";
        int start = intervals[0][0]; int end = intervals[0][1];
        vector<vector<int>>ans;
        for (int i=1;i<intervals.size();i++){
            
            if (intervals[i][0]> end){
                ans.push_back({start, end});
                start = intervals[i][0]; end = intervals[i][1];
            }
            else
                end= max(end,intervals[i][1]);   
        }
        ans.push_back({start,end});
        return ans;
    }
};