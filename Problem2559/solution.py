""" 
Let n be the size of words
Let m be the size of queries

Time Complexity: O(n+m)
Space Complexity: O(n+m)

A simple and easy solution in python with prefix sum.

"""

class Solution:
    def validStringVowels(self, word:str):
        vowels:dict = {'a', 'e', 'i', 'o', 'u'}
        if word[0] in vowels and word[-1] in vowels:
            return 1
        return 0

    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        hasVowel:list[int] = [0]*len(words)

        for i in range(0, len(hasVowel)):
            hasVowel[i] = hasVowel[i-1] + Solution.validStringVowels(self, words[i])

        ans:list[int] = []

        for querie in queries:
            if querie[0] == 0:
                ans.append(hasVowel[querie[1]])
            else:
                ans.append(hasVowel[querie[1]] - hasVowel[querie[0] - 1])

        return ans
    
sol:Solution = Solution()
words = ["aba","bcb","ece","aa","e"]
queries = [[0,2],[1,4],[1,1]]
print(sol.vowelStrings(words, queries))