""" 
Let n be the number of nodes in the list

Time Complexity: O(n)
Space Complexity: O(1)

A simple and easy two pointers solution.

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        p = head
        q = head
        while p.next is not None:
            if p.next.next is not None:
                p = p.next.next
            else:
                p = p.next
            q = q.next
        return q
    
sol:Solution = Solution()
p = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6))))))
print(sol.middleNode(p).val)