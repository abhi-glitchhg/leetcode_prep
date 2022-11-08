class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int, vector<int>, greater<int> > first;
        priority_queue<int, vector<int>, greater<int> > second;
        int start=0;
        for ( start=0; start<candidates;start++){
            first.push(costs[start]);
        }
        int end= costs.size()-1;
        for (int i=0; i<candidates;i++){
            if (start<=end){
                second.push(costs[end]);
                end--;
            }
        }
        
        
        for (int i=0;i<k;i++){
            cout<< start<< " "<<end;
            //if (first.empty() && start>end) {ans+=second.top(); second.pop();}
            //else if (second.empty() && start>end){ans+= first.top(); first.pop();}
            
            if (!first.empty() && !second.empty())
            {if (first.top()<=second.top()){
                ans+=first.top();
                first.pop();
                if (start<=end){
                  first.push(costs[start]);
                    start++;
                }
            
            }
            else {
                ans+=second.top();
                second.pop();
                if (start<=end){
                    second.push(costs[end]);
                    end--;
                }
            }}
            else if (first.empty()) {ans+=second.top(); second.pop();}
            else if (second.empty() ){ans+= first.top(); first.pop();}
            
            
        }
        return ans;
        
        
    }
};