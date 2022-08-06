class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows == 1:
            return s
        res = [""]* numRows
        res[0] = s[0]
        
        #print(res,len(res))
        j = 0 
        i = 1
        while (i<len(s)):
            for j in range(1,numRows):
                if i == len(s):
                    break
                #print(i,j)
                res[j] += s[i]
                i+=1
                
            for j in range(numRows-2,-1,-1):
                if i == len(s):
                    break
                #print(i,j)
                res[j] += s[i]
                i+=1
        ans=""
        for f in res:
            ans+=f
        return ans
                
        
            