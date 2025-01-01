/* 
Let n be inputStr.size()

Time Complexity: O(n)
Space Complexity: O(1)

A simples solution in cpp.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(string inputStr) {
        int onesCount = 0;
        int zerosCount = 0;
        int bestScore = 0;

        for (int i = 0; i < inputStr.size() - 1; i++) {
            if (inputStr[i] == '1') {
                onesCount++;
            } else {
                zerosCount++;
            }
            
            bestScore = max(bestScore, zerosCount - onesCount);
        }
        
        if (inputStr[inputStr.size() - 1] == '1') {
            onesCount++;
        }
        
        return bestScore + onesCount;
    }
};

int main(){
    Solution sol = Solution();
    string s = "011101";
    cout << sol.maxScore(s) << endl; // 5
}