class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool flag = true;

        if (s[0] == '-'){
            s=string (s.begin()+1,s.end());
            flag= false;
        }

        int i = 0;
        int j = s.size()-1;
        while(j>i){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        int ans= 0;
        try{
             ans= stoi(s);
        }
        catch(std::out_of_range) {
            return 0;
        }
        if (!flag) ans=ans*(-1);            
        return ans;
    }
};