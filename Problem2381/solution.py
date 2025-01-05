""" 
Let n be the size of the string `s`
Let m be the size of the list `shifts`

Time Complexity: O(n+m)
Space Complexity: O(n)

"""
class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        presum = [0]*(len(s)+1)

        for shift in shifts:
            if shift[2] == 1:
                presum[shift[0]] += 1
                presum[shift[1] + 1] += -1
            else:
                presum[shift[0]] += -1
                presum[shift[1] + 1] += 1
        
        shift:int = 0
        ans:str = ""
        for i in range(0, len(s)):
            shift = (shift + presum[i]) % 26
            ans += chr(ord('a') + ((ord(s[i]) - ord('a')) + shift) % 26)
        
        return ans
    
sol:Solution = Solution()
s = "abc"
shifts = [[0,1,0],[1,2,1],[0,2,1]]
print(sol.shiftingLetters(s, shifts))