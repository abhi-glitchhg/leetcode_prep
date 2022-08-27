// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        else if (isBadVersion(n) && !isBadVersion(n-1)) return n;
        int start=0;
        int end = n-1;
        int mid=0;;
        while(start<=end){
            // int mid = (start+end)/2;
            int mid =  start + (end-start)/2;//this is done to prevent the overflow
            if (isBadVersion(mid) && !isBadVersion(mid-1)) return mid;
             else if(isBadVersion(mid)){
                end = mid - 1;
                if (start ==end) return end;
            }
            else if(! isBadVersion(mid)){
                start = mid + 1;
                if (start ==end) return start;
            }
        }
        return mid;
    }
};