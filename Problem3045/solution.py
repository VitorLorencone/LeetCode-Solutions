"""
Time Complexity: log(nm)
Space Complexity: log(nm)
"""

from collections import *

class Solution:
    def countPrefixSuffixPairs(self, words: list[str]) -> int:
        root = (T := lambda: defaultdict(T))()
        res = 0
        for w in words:
            x = root
            for k in zip(w, reversed(w)):
                res += (x := x[k]).get(0, 0)
            x[0] = x.get(0, 0) + 1
        return res
    
sol:Solution = Solution()
words = ["a","aba","ababa","aa"]

print(sol.countPrefixSuffixPairs(words))