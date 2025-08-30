/* 
Time Complexity: O(log|x|)
Space Complexity: O(1)
*/

#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x)>abs(z-y)) return 2;
        else if(abs(z-x)<abs(z-y)) return 1;
        else return 0;
    }
};

int main(){

    Solution sol = Solution();
    int x = 1;
    int y = 5;
    int z = 3;

    cout << sol.findClosest(x, y, z) << endl;

}