class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            if target-nums[i]  in nums:
                ans= nums.index(target - nums[i])
                if ans!=i:
                    ans =[i,ans]
                    break
        return ans