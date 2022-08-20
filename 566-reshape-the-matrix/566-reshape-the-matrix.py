class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        ans1 = []
        ans2 =[]
        
        if r*c != len(mat) * len(mat[0]):
            return mat
        
        else:
            
            for i in mat:
                ans1.extend(i)
            idx = 0
            while idx < len(ans1):
                tmpCol = []
                for col in range(c):                
                    tmpCol.append(ans1[idx])
                    idx +=1
                ans2.append(tmpCol)
                
            return ans2