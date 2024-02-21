/* 

Time Complexity: O(log(n))
Space Complexity: O(1)

A very simple solution using bitwise operations. It strarts checking for special cases, including one that
searches for a power of 2 and the goes with a fast calculation using O(log(n)) time complexity.

*/

#include <iostream>
#include <math.h>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        if(left == right){return left;}
        if(left == 0){return 0;}
        if(log(right)/log(2) - log(left)/log(2) >= 1 || (right&(right-1)) == 0){return 0;}

        int pos=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            pos++;
        }
        return left<<pos;
    }
};

int main(){

    Solution sol = Solution();
    int l = 5;
    int r = 7;

    std::cout << sol.rangeBitwiseAnd(l,r) << std::endl;

}
