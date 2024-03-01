""" 
Let n be the number of nodes in the tree and h be the height of the tree

Time Complexity: O(n)
Space Complexity: O(h)

A recursive solution using dfs.

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    value:int = 0
    currentLevel:int = 0

    def dfs(self, node:TreeNode, level = 0):
        if node is None:
            return
    
        if level > self.currentLevel:
            self.value = node.val
            self.currentLevel = level

        self.dfs(node.left, level+1)
        self.dfs(node.right, level+1)
    
    def findBottomLeftValue(self, root: TreeNode) -> int:
        self.value = root.val
        self.dfs(root)
        return self.value
    
sol:Solution = Solution()
root = TreeNode(1, TreeNode(2, TreeNode(4), None), TreeNode(3, TreeNode(5, TreeNode(7, None)), TreeNode(6)))
print(sol.findBottomLeftValue(root))