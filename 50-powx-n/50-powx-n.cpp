class Solution {
public:
    double myPow(double x, int n) {
        
        double pow = 1;
        if(n<0)
          x = 1/x;
        
        long num = labs(n);
        while(num!=0)
        {
            if(num&1)
                pow *=x;
            
            x *= x;
            //cout<<num<<" ";
            num = num>>1;
            //cout<<num <<" " <<pow<<endl;
        }
        return pow;
        
    }
};