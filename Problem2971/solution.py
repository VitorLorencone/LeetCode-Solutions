"""

Time Complexity: O(nlog(n))
Space Complexity: O(1)

Solution using the python sort, with n*log(n) complexity and greedy algorithm in O(n).
It was improved in the .cpp file

"""

class Solution:
    def largestPerimeter(self, nums: list[int]) -> int:
        s = 0
        nums.sort()
        
        for i in range(len(nums)-2):
            for j in range(len(nums)-i-1):
                s += nums[j]
            if s > nums[-i-1]:
                return s+nums[-i-1]
            s = 0
        return -1
    
sol:Solution = Solution()
prob:list[int] = [1,12,1,2,5,50,3]
print(sol.largestPerimeter(prob))