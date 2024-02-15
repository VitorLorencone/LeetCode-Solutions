"""

Time Complexity: O(n)
Space Complexity: O(n)

Solution using deque like a queue for O(1) append and pop and to keep elements in order.
The ideia uses a waiting queue, to keep the other sign elements in there, while the solution comes up in order.

"""

from collections import deque

def numSign(n:int) -> bool:
    if n >= 0:
        return 1
    return -1

class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        sign:int = 1
        solution:list = []
        waiting = deque()

        for i in nums:
            if len(waiting) > 0 and sign == numSign(waiting[0]):
                solution.append(waiting[0])
                waiting.popleft()
                sign *= -1
            if sign == numSign(i):
                solution.append(i)
                sign *= -1
            else:
                waiting.append(i)

        if len(waiting) > 0:
            solution.append(waiting[0])

        return solution
    
sol:Solution = Solution()
prob:list[int] = [3, 1, -2, -5, 2, -4]
print(sol.rearrangeArray(prob))