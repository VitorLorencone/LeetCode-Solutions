"""
let k be len(meetings)

Time Complexity: O(klog(k))
Space Complexity: O(n)

Solution using two python heapq for keeping track of many values that needed to be in an order.

"""
import heapq

class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        freq:list = list(0 for i in range(n))
        booked:list = []
        free:list = list(range(n))
        room:int = 0
        release:int = 0
        result:int = 0
        meetings.sort()

        for start, end in meetings:

            while len(booked) > 0 and booked[0][0] <= start:
                room = heapq.heappop(booked)[1]
                heapq.heappush(free, room)

            if len(free) > 0:
                room = heapq.heappop(free)
                heapq.heappush(booked, [end, room])
            else:
                release, room = heapq.heappop(booked)
                heapq.heappush(booked, [end-start+release, room])
            
            freq[room] += 1

        for i in range(n):
            if freq[i] > freq[result]:
                result = i
                
        return result
    
sol:Solution = Solution()
prob1:int = 3
prob2:list[list[int]] = [[1,20],[2,10],[3,5],[4,9],[6,8]]
print(sol.mostBooked(prob1, prob2))