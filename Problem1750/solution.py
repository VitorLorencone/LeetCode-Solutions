""" 
Let n be len(tokens)

Time Complexity: O(nlog(n))
Space Complexity: O(1)

A solution using greedy, two pointers and sort.

"""

class Solution:
    def bagOfTokensScore(self, tokens: list[int], power: int) -> int:
        tokens.sort()
        points:int = 0
        maxPoints:int = 0
        p:int = 0
        q:int = len(tokens)-1
        
        for i in range(len(tokens)):
            if(tokens[p] <= power):
                power -= tokens[p]
                p += 1
                points += 1
                maxPoints = max(maxPoints, points)
                continue
            elif(points > 0):
                power += tokens[q]
                q -= 1
                points -= 1
                continue
            break
        return maxPoints
    
sol:Solution = Solution()
tks:list = [100,200,300,400]
pwr:int = 200
print(sol.bagOfTokensScore(tks, pwr))