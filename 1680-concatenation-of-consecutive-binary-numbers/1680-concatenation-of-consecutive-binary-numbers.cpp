class Solution {
public:
    int concatenatedBinary(int n) {
        int i=0;
        int divide= 1000000007;
        int arr[20];  // starting with an array of size 20;
        
        for (;i<20;i++)
            arr[i]=((int)pow(2,i)); // fill the array with powers of 2;
        for (i = 19; i>=0 ;i--)
            if (arr[i]<=n) break; 
        int size_ = i+1;  //find the len of the binary representation of n;
        long long ans =0;
        long long  int power = 1; // we multiply the jth number with this power factor..
        for (int j=n;j>0;j--){
            if (arr[size_-1]>j) size_-=1;
            ans += j * power;
            ans %= divide;  
            power = power * (int)pow(2,size_);
            power = power % divide; // using properties of modulo operations and to keep power in the premissive limits.
        }
        return ans;
    }
};