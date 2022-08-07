class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]
        elif len(nums)==1 and target in nums:
            return [0,0]
        else:
            s1 = nums.index(target)
            print(s1)
            x=1
            while s1+x<len(nums):
                
                if nums[s1]==nums[s1+x]:
                    x+=1
                else:
                    break
            return [s1,s1+x-1]