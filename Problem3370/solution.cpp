/* 
'k' is the number of bits in n
Time Complexity: O(k), but it's usually considered O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        return (1<<(64-__builtin_clzll(n)))-1;
    }
};

int main(){
    Solution sol = Solution();
    int n = 5;
    cout << sol.smallestNumber(n);
}