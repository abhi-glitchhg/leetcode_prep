class Solution {
public:
    int longestPalindrome(string s) {
        map <char,int> map_;
        if (s.size() <2) return s.size();
        
        for (char x:s)
            map_[x]++;
        bool is_one = false;
        int sol = 0;
        for (const auto i:map_){
            sol+=i.second;
            if (i.second%2==1) {
                is_one=true;
                sol--;}

            

        }
        if (is_one) sol++;
        return sol;
        
    }
};