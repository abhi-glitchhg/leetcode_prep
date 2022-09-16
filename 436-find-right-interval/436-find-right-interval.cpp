class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      map<int,int> a;
      vector<int> gg;
      vector<int> ans;
      int counter =0;  
      for (auto i : intervals){
          a[i[0]] = counter;
          gg.push_back(i[0]);
          counter++;
      }
        sort(gg.begin(), gg.end());
        
        for  (auto i: intervals){
            int temp = binarySearch(gg,i[1]);
            //cout <<temp<<endl;
            if (temp == -1) ans.push_back(-1);
            else ans.push_back(a[gg[temp]]);
        }
        return ans;
        
    }
    
       int binarySearch(vector<int> &inv, int end) {
        int lo = 0, hi=inv.size()-1;
        int ans=-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(inv[mid] >= end){
                ans = mid; // index
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
       }
};