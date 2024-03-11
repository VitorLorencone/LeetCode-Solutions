"""
Let n be len(nums1) == len(nums[2])

Time Complexity: O(nlog(n))
Space Complexity: O(n)

Solution using hash table for counting and sorting with nlog(n) algorithm

"""

class Solution:
    def bSearch(self, array:list, val:int):
            end:int = len(array) - 1
            start:int = 0
            while(start <= end):
                middle:int = (start+end)//2
                if(array[middle] == val):
                    return True
                elif(array[middle] < val):
                    start = middle+1
                else:
                    end = middle-1
            return False

    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        ans:dict = {}
        sArray:list = nums2 if len(nums1) > len(nums2) else nums1
        bArray:list = nums1 if len(nums1) > len(nums2) else nums2
        bArray.sort()

        for i in sArray:
            if self.bSearch(bArray, i) == True:
                ans[i] = 1

        return ans.keys()
    
sol:Solution = Solution()
order:str = "bcafg"
s:str = "abcd"
print(sol.customSortString(order, s))