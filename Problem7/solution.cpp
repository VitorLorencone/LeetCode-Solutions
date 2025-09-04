/* 
Time Complexity: O(log|x|)
Space Complexity: O(1)
*/

#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans{0};
        while(x != 0){
            if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            ans = ans*10 + x%10;
            x /= 10;
        }
        return ans;
    }
};

int main(){

    Solution sol = Solution();
    int x = 123;

    cout << sol.reverse(x) << endl;

}