""" 
Let n be the number of points in the vector

Time Complexity: O(n²)
Space Complexity: O(1)

"""

class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        # Sorting by x ascending and y descending
        points.sort(key=lambda x: (x[0], -x[1]))
        n:int = len(points)

        ans:int = 0
        for i in range(n):
            border:int = -1
            for j in range(i+1, n):
                if points[i][1] >= points[j][1] and points[j][1] > border:
                    ans += 1
                    border = points[j][1]
                    if border == points[i][1]:
                        break
        
        return ans
    
sol:Solution = Solution()
pts:list[list[int]] = [[6,2],[4,4],[2,6]] # 2
print(sol.numberOfPairs(pts))