class Solution {
    
public:
    int maximum69Number (int num) {
        
        int n=0; 
        string gg= to_string(num);
        while( n<= gg.size()){
         if (gg[n]=='6'){
             gg[n]='9';
             cout<<gg<<" ";
             break;
         }
            n++;
            //cout<<n <<" ";
        }
        //cout<<gg<<" ";
        num = stoi(gg);
        return num;
    }
};