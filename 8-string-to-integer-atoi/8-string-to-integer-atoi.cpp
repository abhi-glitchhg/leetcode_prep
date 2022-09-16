class Solution {
public:
    int myAtoi(string s) {
        int gg;
         int sol=0;
        int count =0;
        int flag = 0;
        for (char i: s){
            if (i==' ' && count==0 && flag ==0) continue;
            else if (i==' ' && count==0 && flag ==1) break;
            
            else if (i=='-' || i=='+' ){
                if (flag != 0 && count) break;
                else if (count == 0 && flag!=0) return 0;
                else if ( i-'+')  //if not +;{ 
                    flag=-1 ;
                    
                else flag=1; //if positive
                }
            else if (i>'9' || i<'0') break;
            else  {
                if (flag==0)flag=1;
                if (count==0){
                    count++;
                    if (flag ==1)
                        gg= INT_MAX;
                    else
                        gg=INT_MIN;
                }
                //cout << sol<<endl;
            if (sol*flag < INT_MAX/10) sol *= 10 ;
            else if (sol*flag == INT_MAX/10 && i<='6') sol *= 10 ; 
            else if (sol*flag == INT_MAX/10 && i=='7' && flag==-1) sol *= 10 ;
            else return gg;
            
            sol += flag * (i-'0');
            //else return gg;
            }
            }
        
        return sol;
    }
};