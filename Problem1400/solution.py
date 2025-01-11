"""
let n be the length of `s`

Time Complexity: O(n)
Space Complexity: O(n)

"""

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        letters:dict = {}
        oddLetters = 0

        if len(s) == k:
            return True
        if len(s) < k:
            return False

        for l in s:
            if l in letters:
                letters[l] += 1
            else:
                letters[l] = 1
            oddLetters += 2*(letters[l]%2) - 1

        return oddLetters <= k
    
sol:Solution = Solution()
s:str = "annabelle"
k:int = 2
print(sol.canConstruct(s, k))