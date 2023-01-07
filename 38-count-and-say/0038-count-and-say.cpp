class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string ans="11";
        for (int i=0;i<n-2;i++){
            int index =0;
            int count=0;
            string new_ans="";
            while (index<ans.size()-1){
                count++;
                if (ans[index]!=ans[index+1]){
                    new_ans+=to_string(count);
                    new_ans+= ans[index];
                    count=0;
                }
                index++; 
            }
            if (ans[index]!=ans[index-1])
            {new_ans+='1'; new_ans+=ans[index];
            }
            else{
                new_ans+=to_string(count+1); new_ans+=ans[index];
            }
            //cout<<new_ans<<" ";
            ans=new_ans;
            
        }
        return ans;
    }
};