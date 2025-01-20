"""
Time Complexity: O(n)
Space Complexity: O(n)

"""

class Solution:
    def firstCompleteIndex(self, arr: list[int], mat: list[list[int]]) -> int:
        num_rows, num_cols = len(mat), len(mat[0])
        row_count, col_count = [0] * num_rows, [0] * num_cols
        num_to_pos = {}

        for row in range(num_rows):
            for col in range(num_cols):
                num_to_pos[mat[row][col]] = [row, col]

        for i in range(len(arr)):
            num = arr[i]
            row, col = num_to_pos[num]

            row_count[row] += 1
            col_count[col] += 1

            if row_count[row] == num_cols or col_count[col] == num_rows:
                return i

        return -1
    
sol:Solution = Solution()
arr = [1,3,4,2]
mat = [[1,4],[2,3]]
print(sol.firstCompleteIndex(arr, mat))