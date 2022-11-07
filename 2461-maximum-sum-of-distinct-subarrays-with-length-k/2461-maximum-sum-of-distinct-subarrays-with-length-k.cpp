class Solution {
public:
	long long maximumSubarraySum(vector<int>& a, int k) {
		int n=a.size(),j=0;
		unordered_map<int,int> mp;
		long long sum=0,mx=0;
		for(int i=0;i<n;i++) {
			mp[a[i]]++;
			sum+=a[i];
			while(mp[a[i]]>1||i-j+1>k) {
				mp[a[j]]--;
				sum-=a[j++];
			}
			if(i-j+1==k) mx=max(mx,sum);
		}
		return mx;
	}
};