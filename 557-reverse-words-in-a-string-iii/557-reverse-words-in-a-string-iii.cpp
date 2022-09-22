class Solution {
public:
    string reverseWords(string s) {
        stringstream  ss(s);
        string ans ="";
        string temp="";
        while (getline(ss,temp, ' ')){
            int num = temp.size();
            for (int i=0;i<num/2;i++){
               swap(temp[i], temp[num-1-i]);
            }
                
            ans+=temp;
            ans+= ' ';
        }
        return string(ans.begin(), ans.end()-1);
        
    }
};
