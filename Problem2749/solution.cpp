/* 
Time Complexity: O(1)
Space Complexity: O(1)
*/

// Fun fact, only 36 operations can be made at maximum with the constraints of the problem
// because the biggest number to be made with n operations is 10^9*(n+1) thus, the number 
// of bits of this number is log2(10^9*(n+1)). When n = 36 or anything to 60 the number of 
// bits in 10^9*(n+1) is also 36.

#include <iostream>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 >= num1) return -1;
        long long x = num1;
        for(int i = 1; i <= 36; i++){
            x -= static_cast<long long>(num2);
            if (x < i) {return -1;}
            if (i >= __builtin_popcountll(x)) {return i;}
        }
        return -1;
    }
};

int main(){

    Solution sol = Solution();
    int num1 = 3;
    int num2 = -2;

    cout << sol.makeTheIntegerZero(num1, num2) << endl; // 3

}