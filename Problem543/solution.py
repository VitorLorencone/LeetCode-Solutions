"""
Time Complexity: O(n)
Space Complexity: O(1)

Something interesting is that this algorithm has a specific name and creators, it's called 
the Boyer Moore majority voting algorithm and it's amazing for achieving this result of time 
and memory complexity. Its operation is quite simple, yet ingenious
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p is None and q is None:
            return True
        elif p is None or q is None:
            return False
    
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) and p.val == q.val
    
sol:Solution = Solution()
p = TreeNode(1, TreeNode(2), TreeNode(3))
q = TreeNode(1, TreeNode(2), TreeNode(3))
print(sol.isSameTree(p, q))

p = TreeNode(1, None, TreeNode(2))
q = TreeNode(1, TreeNode(2), None)
print(sol.isSameTree(p, q))