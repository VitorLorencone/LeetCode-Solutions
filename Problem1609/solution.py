""" 
Let n be the number of nodes in the tree and h be the height of the tree

Time Complexity: O(n)
Space Complexity: O(n) -> values vector use O(h) but the worst case in call stack is O(n)

A recursive solution using dfs.

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    solution:bool = True

    def isEvenOddTree(self, root: TreeNode) -> bool:
        values:list = []

        def solver(node: TreeNode, level:int = 0) -> None:
            sign:int = -2*(level%2)+1
            if node is None or self.solution == False:
                return
            if node.val%2 == level%2:
                self.solution = False
                return
            if len(values) <= level:
                values.append(node.val)
            elif values[level]*sign < node.val*sign:
                values[level] = node.val
            else:
                self.solution = False
            solver(node.left, level+1)
            solver(node.right, level+1)

        solver(root)
        return self.solution
    
sol:Solution = Solution()
root:TreeNode = TreeNode(5, TreeNode(4, TreeNode(3), TreeNode(5)), TreeNode(2, TreeNode(7), None))
print(sol.isEvenOddTree(root))