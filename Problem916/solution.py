"""
let `w1` be the size of `words1`
let `w2` be the size of `words2`
let `n` be the average amount of letter in words from `words1`
let `m` be the average amount of letter in words from `words2`

Time Complexity: O(w1*n + w2*m)
Space Complexity: O(w1)

"""

class Solution:
    def wordSubsets(self, words1: list[str], words2: list[str]) -> list[str]:
        maxCharFreq = [0] * 26
        tempCharFreq = [0] * 26

        for word in words2:
            for ch in word:
                tempCharFreq[ord(ch) - ord('a')] += 1
            for i in range(26):
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i])
            tempCharFreq = [0] * 26

        universalWords = []

        for word in words1:
            for ch in word:
                tempCharFreq[ord(ch) - ord('a')] += 1
            isUniversal = True
            for i in range(26):
                if maxCharFreq[i] > tempCharFreq[i]:
                    isUniversal = False
                    break
            if isUniversal:
                universalWords.append(word)
            tempCharFreq = [0] * 26

        return universalWords
    
sol:Solution = Solution()
words1 = ["amazon","apple","facebook","google","leetcode"]
words2 = ["e","o"]
print(sol.wordSubsets(words1, words2))