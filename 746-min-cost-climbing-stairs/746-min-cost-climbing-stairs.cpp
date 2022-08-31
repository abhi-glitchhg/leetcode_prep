class Solution {
public:
   int minCostClimbingStairs(vector<int>& cost) {
  /*     int max_size = cost.size();
       vector<int>  v(cost.size());
        for (int i =0;i<cost.size();i++)
            v[i]=-1;
       return min(travel(0,cost, v),travel(1,cost,v)) ;
    }    
    int travel(int index, vector<int>& cost,vector<int>& v){ 
        if (index==cost.size()-2 || index==cost.size()-1) return cost[index];
        if (v[index]==-1)
            v[index] = cost[index] + min(travel(index+1, cost,v), travel(index+2, cost,v));
        return v[index];*/
       int a  = cost[0];
       int b = cost[1];
       int c = 0;
       for (int i=2; i< cost.size(); i++){
           c = cost[i] + min(a,b);
           a=b;
           b=c;
       }
       return min(a,b);
       
       
       
    }
    
};