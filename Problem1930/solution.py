""" 
Let n be the size of the string `s`

Time Complexity: O(n^2)
Space Complexity: O(n)

"""
class Solution:
    def uniqueLetters(self, s:str) -> int:
        letters:dict = {}
        ans:int = 0
        for letter in s:
            if not letter in letters:
                ans += 1
                letters[letter] = 1
        return ans

    def countPalindromicSubsequence(self, s: str) -> int:
        ranges:dict = {}

        for index in range(0, len(s)):
            if s[index] in ranges:
                ranges[s[index]][1] = index
            else:
                ranges[s[index]] = [index, -1]
        
        ans:int = 0
        for letter in ranges:
            if ranges[letter][1] != -1 and ranges[letter][1] - ranges[letter][0] > 1:
                ans += Solution.uniqueLetters(self, s[ranges[letter][0]+1 : ranges[letter][1]])
        
        return ans
    
sol:Solution = Solution()
s = "aabca"
print(sol.countPalindromicSubsequence(s))