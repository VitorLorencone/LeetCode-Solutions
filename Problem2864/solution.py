""" 
Let n be the size of s

Time Complexity: O(n)
Space Complexity: O(n)

A simple and easy solution in python counting the ammount of 0's and 1's.

"""

class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        c1 = s.count('1')
        c0 = s.count('0')
        ans = '1' * (c1 - 1) + '0' * c0 + '1'
        return ans
    
sol:Solution = Solution()
s = "00011"
print(sol.maximumOddBinaryNumber(s))