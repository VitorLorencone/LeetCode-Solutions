"""
let n be the length of string `A`

Time Complexity: O(n)
Space Complexity: O(n)

"""

class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        common:dict = {}
        res:list = []
        val:int = 0

        for i in range(len(A)):
            
            if A[i] in common:
                val += 1
            else:
                common[A[i]] = 1
            
            if B[i] in common:
                val += 1
            else:
                common[B[i]] = 1

            res.append(val)
        
        return res
    
sol:Solution = Solution()
A:list = [1,3,2,4]
B:list = [3,1,2,4]
print(sol.findThePrefixCommonArray(A, B))