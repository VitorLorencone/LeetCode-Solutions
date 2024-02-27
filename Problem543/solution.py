"""
Let n be the number of nodes in the tree

Time Complexity: O(n)
Space Complexity: O(n)

Solution with a recursive dfs

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res = 0
        def dfs(node):
            if not node:
                return 0
            
            left = dfs(node.left) 
            right = dfs(node.right)
            self.res = max(self.res, left+right)
            return 1 + max(left, right)
        dfs(root)
        return self.res
    
sol:Solution = Solution()
p = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
print(sol.diameterOfBinaryTree(p))