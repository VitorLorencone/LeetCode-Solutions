"""
let n be len(heights)
let k be len(p)

Time Complexity: O(n*log(k))
Space Complexity: O(k)

Solution using the python priority queue to storage elements we will need to access
in a certain order. The heapq.heappush(p, -difference) helps in ordering the queue in
the opposite order so we can use heapq.heappop(p) correctly. Since heap.heappush and
heap.heappop() have O(log(k)) time complexity, then we could measure the above complexity

"""
import heapq

class Solution:
    def furthestBuilding(self, heights: list[int], bricks: int, ladders: int) -> int:
        p:heapq = []
        difference:int = 0
        count:int = 0

        for i in range(len(heights) - 1):
            difference = heights[i+1] - heights[i]
            if(difference <= 0):
                count += 1
                continue
            bricks -= difference
            heapq.heappush(p, -difference)
            if bricks < 0:
                bricks += -heapq.heappop(p)
                ladders -= 1
            if ladders < 0:
                break
            count += 1

            print(p)
        return count
    
sol:Solution = Solution()
prob1:list[int] = [4,12,2,7,3,18,20,3,19]
prob2:int = 10
prob3:int = 2
print(sol.furthestBuilding(prob1, prob2, prob3))