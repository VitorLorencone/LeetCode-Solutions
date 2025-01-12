"""
let n be the length of `s`

Time Complexity: O(n)
Space Complexity: O(n)

"""

class Solution:
    def canBeValid(self, s, locked):
        length = len(s)

        if length % 2 == 1:
            return False

        open_brackets = []
        unlocked = []

        for i in range(length):
            if locked[i] == "0":
                unlocked.append(i)
            elif s[i] == "(":
                open_brackets.append(i)
            elif s[i] == ")":
                if open_brackets:
                    open_brackets.pop()
                elif unlocked:
                    unlocked.pop()
                else:
                    return False

        while open_brackets and unlocked and open_brackets[-1] < unlocked[-1]:
            open_brackets.pop()
            unlocked.pop()

        if open_brackets:
            return False

        return True
    
sol:Solution = Solution()
s:str = "))()))"
locked:str = "010100"
print(sol.canBeValid(s, locked))