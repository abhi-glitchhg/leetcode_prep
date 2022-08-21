class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        int total = 0;
        while (true){
            sort(amount.rbegin(), amount.rend());
            if (amount[0] == 0  ) break;
            else if (amount[1] == 0) { 
                total+=amount[0]; 
                amount[0] = 0;
                break;
                }
            else{
                amount[0]--;
                amount[1]--;
                total++;
            }
        }
        return total;
    }
};