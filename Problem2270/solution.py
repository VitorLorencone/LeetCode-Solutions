""" 
Let n be the size of `nums`

Time Complexity: O(n)
Space Complexity: O(1)

A simple and easy solution in python.

"""
class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        total:int = 0
        for i in nums:
            total += i
        nums.pop()

        ans:int = 0
        acc:int = 0
        for i in nums:
            acc += i
            if 2*acc >= total:
                ans += 1

        return ans
    
sol:Solution = Solution()
nums = [10,4,-8,7]
print(sol.waysToSplitArray(nums))