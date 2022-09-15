class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        for (string s:strs) {
            int size_ = s.size();
            min_len = min(min_len, size_);
            }
        if (min_len ==0) return "";
        string first = strs[0];
        string common = string(first.begin(), first.begin() + min_len);
        
        for (int i=1; i<strs.size(); i++){
            string tocompare = strs[i];
            
            for (int j=0;j<min_len;j++) {if ( tocompare[j] != common[j]) min_len = j; if (min_len == 0 ) return "";}
        }
        
        common = string(first.begin(), first.begin() + min_len);
        return common;
    }
};