"""

let grid be an mxn matrix.

Time Complexity: O(n*m)
Space Complexity: O(n+m)

"""

class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        rows:list[int] = [0]*len(grid)
        cols:list[int] = [0]*len(grid[0])

        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                rows[i] += grid[i][j]
                cols[j] += grid[i][j]

        ans:int = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == 1 and (rows[i] > 1 or cols[j] > 1):
                    ans += 1

        return ans
    
sol:Solution = Solution()
grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
print(sol.countServers(grid))
