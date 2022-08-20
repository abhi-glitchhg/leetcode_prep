class Solution {
public:
    uint32_t reverseBits(uint32_t n) { 
        int res =0;
        for (int i=0; i<32;i++){
        //lets find out the lsb
        int lsb = n & 1;
        //cout<< lsb;
        int reversed =  lsb << (31 - i);
        n=n>>1;
        res= res | reversed;}
        return res;
        
        
        
    }
};
