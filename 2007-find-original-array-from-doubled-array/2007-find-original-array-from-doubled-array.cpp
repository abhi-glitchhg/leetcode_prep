class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        //
        vector<int> empty;
        //vector<int> ans;
        if (changed.size()%2 ==1 ) return empty;
        vector<int> arr2;
        queue<int> ans;
        sort(changed.begin(), changed.end());
        for (auto i : changed){
            if (ans.empty()) ans.push(i);
            else if (2*ans.front() == i) {arr2.push_back(i/2); ans.pop();}
            else if (2*ans.front() > i) {ans.push(i);}  
            else if (2*ans.front()<i) return empty;
        }
        if (arr2.size() != changed.size()/2) return empty;
        return arr2;
        
    }
};