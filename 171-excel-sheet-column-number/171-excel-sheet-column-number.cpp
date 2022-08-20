class Solution {
public:
    int titleToNumber(string columnTitle) {
     //   map<char,int> dictionary;
        
    //    for (int i=0; i<26;i++){
     //       dictionary[i + 'A'] = i+1;
            
     //   }
      //  int sol = 0;
      //  int sizee = columnTitle.size();
       // for (int i=0; i <columnTitle.size(); i++){
       //     sol += int(pow(26,sizee -i-1)) * dictionary[char(columnTitle[i])];
        //}
        //return sol;
    
    //recursive approach; 
        int ans =0;
        for (int i=0; i<columnTitle.size(); i++){
            ans = ans*26 + (columnTitle[i]- 'A'+1);
        }
        return ans;
    
    }
};