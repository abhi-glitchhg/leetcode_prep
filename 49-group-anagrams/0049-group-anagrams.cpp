class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>>g;
        
        unordered_map<string,vector<string> > mapping;
        
        for (auto i: strs){
            vector<int> word_count(26,0);
            for (auto j:i)
                word_count[j-'a']++;
            string res= "";
            for (int j=0; j<26;j++){
                if (word_count[j]==0) continue;
                else res+= (char)('a'+j) + to_string(word_count[j]); 
            
            }
            mapping[res].push_back(i);
        }
        
        for (auto i: mapping)
            g.push_back(i.second);
        return g;
    }
};