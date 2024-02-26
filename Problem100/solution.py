"""

Time Complexity: nlog(n) - worst

Solution with only one line

"""

class Solution:
    def majorityElement(self, a: list[int]) -> int:
        return sorted(a)[len(a)//2]
    
sol:Solution = Solution()
prob:list[int] = [2,2,1,1,1,2,2]
print(sol.majorityElement(prob))