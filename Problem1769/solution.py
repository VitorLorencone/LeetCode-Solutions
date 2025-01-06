""" 
Let n be the size of the string `boxe`

Time Complexity: O(n)
Space Complexity: O(n)

"""
class Solution:
    def minOperations(self, boxes: str) -> list[int]:
        leftBalls:int = 0
        rightBalls:int = 0
        ans:list[int] = [0]
        
        for i in range(0, len(boxes)):
            if boxes[i] == "1":
                rightBalls += 1
                ans[0] += i

        if boxes[0] == "1":
            leftBalls += 1
            rightBalls -= 1

        for j in range(1, len(boxes)):
            ans.append(ans[-1] - rightBalls + leftBalls)

            if boxes[j] == "1":
                leftBalls += 1
                rightBalls -= 1

        return ans
    
sol:Solution = Solution()
boxes = "001011"
print(sol.minOperations(boxes))