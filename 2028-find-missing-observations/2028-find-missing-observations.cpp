class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        
        int remaining_ =(rolls.size() + n) * mean;
        int i=0;
        vector<int> a;
        for (auto i: rolls)
            remaining_ -= i;
        int leftover = remaining_%n;
        int div = remaining_ /n;
        
        if (div>6 || remaining_ < n || (div==6 && leftover>0) )
            return a;

        else {
            for (;i<leftover;i++)
                a.push_back(div +1);
            for (;i<n;i++)
                a.push_back(div);
        }
        return a;
    }
};