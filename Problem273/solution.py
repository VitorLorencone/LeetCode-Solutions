"""
Let n be ⌊log_100(num)⌋ the number of chunks

Time Complexity: O(n) or O(log(num))
Space Complexity: O(n) or O(log(num))

Because the vector chunks will increase acording to n and the function chunksToWords will execute n times in main code

"""

class Solution:

    units:list[str] = ["", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "]
    dozens:list[str] = ["", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "]
    highOrders:list[str] = ["", "Thousand ", "Million ", "Billion "]
    chunks:list[int] = []
    ans:str = ""

    def chunksToWords(self, num:int) -> str:
        resp:str = ""

        if num == 0 or num > 999: return resp
        elif num < 20: 
            resp = self.units[num]
        elif num < 100: resp = self.dozens[int(num/10)] + self.units[num%10]
        else: 
            resp += self.units[int(num/100)] + "Hundred "
            if (int(num/10))%10 == 1:
                resp += self.units[num%100]
            else:
                resp += self.dozens[(int(num/10))%10] + self.units[num%10]

        return resp
    

    def numberToWords(self, num:int) -> str:
        if num == 0:
            return "Zero"

        while num != 0:
            self.chunks.append(num%1000)
            num = int((num-num%1000)/1000)

        for i in range(len(self.chunks)-1, -1, -1):
            self.ans += self.chunksToWords(self.chunks[i])
            if self.chunks[i] != 0:
                self.ans += self.highOrders[i]

        self.ans = self.ans[:-1]
        return self.ans
    
sol:Solution = Solution()
num = 1234567
print(sol.numberToWords(num))