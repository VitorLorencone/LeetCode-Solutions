"""
let n be len(words)
let m be the average length of each `word`

Time Complexity: O(n^2*m)
Space Complexity: O(1)

An easy brute force solution in python.

"""

class Solution:
    def countPrefixSuffixPairs(self, words: list[str]) -> int:
        ans:int = 0
        for i in range(0, len(words)):
            for j in range(i+1, len(words)):
                if len(words[i]) > len(words[j]):
                    continue
                if words[j][0:len(words[i])] == words[i] and words[j][-len(words[i]):] == words[i]:
                    ans += 1
        return ans
    
sol:Solution = Solution()
words = ["pa","papa","ma","mama"]
print(sol.countPrefixSuffixPairs(words))