class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for (int i=0;i<n-1;i++){
            prices[i] =  prices[i+1] - prices[i];
        }
        int profit = 0;
        int sum_=0;
        for (int i=0; i<n-1;i++){ 
            sum_ +=prices[i];
            profit=max(profit,sum_);
            sum_= max(sum_,0);
        }
        
        //profit = max(profit,0);
        return profit;
        
    }
};

/*class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        for i in range(n-1):
            prices[i]=prices[i+1]-prices[i]
        
        profit = 0
        sum_=0
        for i in range(n-1):
            sum_ +=prices[i]
            profit=max(profit,sum_)
            
            sum_= max(sum_,0)
        profit = max(profit,0)
        
        return profit*/