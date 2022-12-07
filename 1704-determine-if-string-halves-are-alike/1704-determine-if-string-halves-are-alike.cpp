class Solution {
public:
    bool halvesAreAlike(string s) {
        int s_size = s.size()-1;
        int nums1 = 0;
        int nums2=0;
        for (int i=0;i<s.size()/2;i++){
            if (s[i] == 'a' || s[i]=='A' || s[i]=='e' || s[i]== 'E' || s[i]== 'i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' ||s[i]=='U' )
                            nums1++;
if (s[s_size -i] == 'a' || s[s_size -i]=='A' || s[s_size -i]=='e' || s[s_size -i]== 'E' || s[s_size -i]== 'i' || s[s_size -i]=='I' || s[s_size -i]=='o' || s[s_size -i]=='O' || s[s_size -i]=='u' ||s[s_size -i]=='U' )
                            nums2++;
            
        }
        return (nums1==nums2);
        
        //return true;
    }
};