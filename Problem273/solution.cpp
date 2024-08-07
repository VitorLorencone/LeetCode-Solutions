/* 
Let n be ⌊log_100(num)⌋ the number of chunks

Time Complexity: O(n) or O(log(num))
Space Complexity: O(n) or O(log(num))

Because the vector chunks will increase acording to n and the function chunksToWords will execute n times in main code

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

    vector<string> units = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> dozens = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    vector<string> highOrders = {"", "Thousand ", "Million ", "Billion "};
    vector<int> chunks = {};
    string ans = "";

public:

    string chunksToWords(int num){
        string resp = "";

        if(num == 0 || num > 999){ return resp; }
        else if(num < 20){ resp = units[num]; }
        else if(num < 100){ resp = dozens[num/10] + units[num%10]; }
        else{ 
            resp += units[num/100] + "Hundred ";
            if((num/10)%10 == 1){
                resp += units[num%100];
            }else{
                resp += dozens[(num/10)%10] + units[num%10];
            }
        }

        return resp;
    }

    string numberToWords(int num) {
    
        if(num == 0){
            return "Zero";
        }

        while(num != 0){
            chunks.push_back(num%1000);
            num = (num-num%1000)/1000;
        }

        for(int i = chunks.size()-1; i >= 0; i--){
            ans += chunksToWords(chunks[i]);
            if(chunks[i] != 0){
                ans += highOrders[i];
            }
        }

        ans.pop_back();
        return ans;

    }
};

int main(){
    Solution sol = Solution();
    int nums = 1234567;
    std::cout << sol.numberToWords(nums);
}