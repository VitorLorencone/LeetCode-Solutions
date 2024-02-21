/* 

Time Complexity: O(1)
Space Complexity: O(1)

A very simple solution using bitwise operations. Since every power of 2 has only one binary digit
at the very start of the number and n-1 will have a bunch of 1's, starting with a zero, because of
the binary subtraction, than, the bitwise & will always be 0 if the number is a power of 2 and any 
number otherwise.

Example:
16 -> 10000
16-1 = 15 -> 01111
16 & 15 = 10000 & 01111 = 00000 = 0

*/

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){return false;}
        return (n&(n-1)) == 0;
    }
};

int main(){

    Solution sol = Solution();
    int prob = 32;
    int prob2 = 33;

    std::cout << sol.isPowerOfTwo(prob) << std::endl;
    std::cout << sol.isPowerOfTwo(prob2) << std::endl;

}
