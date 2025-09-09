/* 
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1);
        dp[1] = 1;
        long long sharing = 0;

        for (int day = 2; day <= n; day++) {
            int start = day - delay;
            if (start >= 1) sharing = (sharing + dp[start]) % MOD;

            int forgetDay = day - forget;
            if (forgetDay >= 1) sharing = (sharing - dp[forgetDay] + MOD) % MOD;

            dp[day] = sharing;
        }
        long long ans = 0;

        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};


int main(){

    Solution sol = Solution();
    int n = 6;
    int delay = 2;
    int forget = 4;
    cout << sol.peopleAwareOfSecret(n, delay, forget) << endl; //5

}