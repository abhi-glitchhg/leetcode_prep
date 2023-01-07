class Solution {
public:
    vector<vector<char>> mapping = {{'a','b','c'}, 
                                    {'d', 'e','f'},
                                    {'g','h','i'},
                                    {'j','k','l'},
                                    {'m','n','o'},
                                    {'p', 'q', 'r', 's'},
                                    {'t','u','v'},
                                    {'w','x','y','z'}
                                   };
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size()==0) return ans;
        rec(digits, 0, "", ans);
        return ans;
        }
    
    
    void rec(string &digit, int index, string word, vector<string> &ans){
        
        if (index==digit.size()){ 
            ans.push_back(word);
        return;}
        
        
        for (auto i:mapping[digit[index]-'2']){
            word+=i;
            rec(digit, index+1,word,ans);
            word.pop_back();
        }
    }

};