/*class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // brute force O(n2) will give TLE for the 10^5 length;
        if (nums.size()<2) return false;

        unordered_map<int, int> mp;
        int summ=0;
        for (int i=0;i<k;i++)
            mp[i]=-2;
        mp[0]=-1;
        for (int i=0;i<nums.size();i++){
            summ+=nums[i];
            if (mp[summ%k]==-2)
                mp[summ%k] = i;  // here i was doing i
            else if (mp[summ%k]<i-1) //sol suggest i and i+1 in above place but doenst matter; i have initialised as 0,-1 instead of 0,0
                return true;
        }
        return false;
    }
};*/


/// above sol gives TLE because of the matrix initialisation... use count method just gonna copy paste the solution here.


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	// initialize the hash map with index 0 for sum 0
        unordered_map<int, int> hashMap{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // if the remainder sum % k occurs for the first time
            if (!hashMap.count(sum % k))
                hashMap[sum % k] = i + 1;
            // if the subarray size is at least two
            else if (hashMap[sum % k] < i)
                return true;
        }
        return false;
    }
};