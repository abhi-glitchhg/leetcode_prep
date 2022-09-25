class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int m = nums1.size();
        
        int cpp = 0;
        int n_p = 0;
        int m_p = 0;
        int n1 =0;
        int n2 =0;
        while (cpp < (n+m)/2+1){
            if (n_p < n && m_p < m){
                if (nums1[m_p] > nums2[n_p] )
                {
                    if (cpp == (n+m)/2 -1)
                        n1 = nums2[n_p];
                    else if (cpp == (n+m)/2)
                        n2 = nums2[n_p];
                    n_p++;
                }
                else 
                {
                    if (cpp == (n+m)/2 -1)
                        n1 = nums1[m_p];
                    else if (cpp == (n+m)/2)
                        n2 = nums1[m_p];
                    m_p++;
                }
                    
            }
            
            else if (n_p <n){
                {
                    if (cpp == (n+m)/2 -1)
                        n1 = nums2[n_p];
                    else if (cpp == (n+m)/2)
                        n2 = nums2[n_p];
                    n_p++;
                }
                
            }
            else     {
                    if (cpp == (n+m)/2 -1)
                        n1 = nums1[m_p];
                    else if (cpp == (n+m)/2)
                        n2 = nums1[m_p];
                    m_p++;
                }
            cpp++;
            
        }
        double ans = 0;
       if ((n+m )%2 ==0 )
           ans = (double) n1 + n2;
        ans/=2;
        if ((n+m )%2 ==1 )  ans = (double) n2;
        //cout << n1 <<" "<< n2;
        return ans;
    }
};