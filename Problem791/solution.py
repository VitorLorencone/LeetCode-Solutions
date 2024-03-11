"""
Let n be len(s)

Time Complexity: O(n)
Space Complexity: O(n)

Solution using hash table for counting and sorting with three O(n) loops

"""

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        letters:dict = {}
        ans:str = ""
        for i in s:
            if i in letters:
                letters[i] += 1
            else:
                letters[i] = 1
        for i in order:
            while i in letters:
                ans += i
                letters[i] -= 1
                if letters[i] == 0: del letters[i]
        for i in s:
            while i in letters:
                ans += i
                letters[i] -= 1
                if letters[i] == 0: del letters[i]
        return ans
    
sol:Solution = Solution()
order:str = "bcafg"
s:str = "abcd"
print(sol.customSortString(order, s))