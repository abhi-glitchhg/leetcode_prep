class Solution {
public:
    int minPartitions(string n) {
        char maax='0';
        for (char i:n)
            maax = max(i,maax);
        return (int) maax-'0';
    }
};