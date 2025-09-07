/* 
Time Complexity: O(nlog(n))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNoZeroInteger(int n){
        while(n){
            if(n%10 == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) if(isNoZeroInteger(i) && isNoZeroInteger(n-i)) return {i, n-i};
        return {};
    }
};

int main(){

    Solution sol = Solution();
    int n = 10000;
    vector<int> ans = sol.getNoZeroIntegers(n);

    cout << ans[0] << " " << ans[1] << endl; // {1, 9999}

}