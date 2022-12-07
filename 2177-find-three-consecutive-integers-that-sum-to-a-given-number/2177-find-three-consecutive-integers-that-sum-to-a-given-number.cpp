class Solution {
public:
    vector<long long> sumOfThree(long long a) {
        
        if (a%3!=0) return {};
        return {a/3-1,a/3,a/3+1};
    }
};