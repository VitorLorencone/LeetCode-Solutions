"""
let n be the length of `derived`.

Time Complexity: O(n)
Space Complexity: O(1)

"""

class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        XOR = 0
        for element in derived:
            XOR = XOR ^ element
        return XOR == 0
    
sol:Solution = Solution()
derived:list = [1,1,0]
print(sol.doesValidArrayExist(derived))