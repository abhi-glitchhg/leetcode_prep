class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        for (int i=0;i<32;i++){
            int lsb = n&1;
            res+=lsb;
            n = n >> 1;
        }
        return res;
        
    }
};