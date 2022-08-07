class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1=="0" or num2=="0")
            return "0";
        
//        int inum1=0;
//        int inum2=0;
//        for (int i=0;i<num1.size();i++){
//            inum1+= pow(10,num1.size()-i-1)*((int)num1[i] -48) ;
//            
//        }
//        for (int i=num2.size()-1;i>-1;i--){
//            inum2+= pow(10,num2.size()-1-i)*((int)num2[i] -48);
//        }
//    
//        
//        int ans = inum1*inum2;
//        string res = "";
//        
//        for (int i=0;i<num1.size()+num2.size();i++){
//            int g = ans % (int)pow(10,i+1);
//            ans=ans-g;
//            res=(char)(((int)g/(int)pow(10,i))+48)+res;
//        }
//        if (res[0]=='0')
//            return res.substr(1,num1.size()+num2.size());
//        return res;

        int m=num1.length(), n=num2.length();
        
        vector<int> result(m+n, 0);    // Max. no. of digits in multiplication = m+n
        
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1; j>=0;j--) {
                int product=(num1[i]-'0')*(num2[j]-'0');
                product+=result[i+j+1];      // Adding the previous value to product
                
                // After the product and addition if we get a 2-digit number , let say 75
                // then 5 remains at result[i+j+1] and 7 is carried to next position (res[i+j])
                result[i+j+1]=product%10;    // The Unit digit remains = product % 10
                result[i+j]+=product/10;     // Adding the Carry ; Carry = product /10
            }
        }
        
        
        int k=0;
        while(k<(m+n)&&result[k]==0)    // Skip leading 0's in multiplication
            k++;
        
        string ans="";
        while(k<(m+n))   
            ans+=(char)(result[k++]+'0');   // Generate String from result vector after removing leading 0's
        
        return ans;
        
        
    }
};