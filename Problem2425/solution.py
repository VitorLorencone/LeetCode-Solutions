"""
let k be len(meetings)

Time Complexity: O(klog(k))
Space Complexity: O(n)

Solution using two python heapq for keeping track of many values that needed to be in an order.

"""

class Solution:
    def xorAllNums(self, nums1: list[int], nums2: list[int]) -> int:
        m:int = len(nums1)
        n:int = len(nums2)

        res:int = 0

        if n % 2 == 1:
            for i in nums1:
                res ^= i

        if m % 2 == 1:
            for j in nums2:
                res ^= j

        return res
    
sol:Solution = Solution()
nums1:list = [2,1,3]
nums2:list = [10,2,5,0]
print(sol.xorAllNums(nums1, nums2))