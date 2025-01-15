/* 
Let n be the size of the list nums

Time Complexity: O(n)
Space Complexity: O(n)

A solution using hash map for counting.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = num1;
        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);
        int currentBit = 0;

        while (setBitsCount < targetSetBitsCount) {
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit++;
        }

        while (setBitsCount > targetSetBitsCount) {
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            currentBit++;
        }

        return result;
    }

private:
    bool isSet(int x, int bit) { return x & (1 << bit); }
    void setBit(int &x, int bit) { x |= (1 << bit); }
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};

int main(){
    Solution sol = Solution();
    int num1 = 3;
    int num2 = 5;
    cout << sol.minimizeXor(num1, num2) << endl;
}