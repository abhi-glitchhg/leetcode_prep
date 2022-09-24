class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        if (s.size() <2) return s.size();
        map<char, int> aa;
        
        
        int point1=0;
        int point2 =1;
        int ans = INT_MIN;
        int sol = 1;
        aa[s[point1]]++;
        while (point2<s.size()){
            if (aa[s[point2]] ==1){
                aa[s[point1]]--;
                point1++;
                sol--;
            }
            else { 
                aa[s[point2]]++;
                point2++;
                sol++;
            }
            ans = max(ans, sol);
        }
        return ans;
    }
};