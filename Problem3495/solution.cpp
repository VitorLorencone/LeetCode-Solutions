/* 
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans{0};
        for(int i = 0; i < queries.size(); i++){
            int j = (31-__builtin_clz(queries[i][0]))/2+1; // For log2
            int k = (31-__builtin_clz(queries[i][1]))/2+1;
            long long pj = 1<<(2*j-2); long long pk = 1<<(2*k); // For 4^x
            long long operations = (pj*(4ll-3ll*j)+pk*(3ll*k-1ll))/3ll; // Sum of a series
            operations -= k*(pk-queries[i][1]-1) + j*(queries[i][0]-pj); // Removing extra sum
            ans += (operations & 0x01? 1 : 0) + operations >> 1;
        }
        return ans;
    }
};

int main(){

    Solution sol = Solution();
    vector<vector<int>> queries = {{1,2},{2,4}};
    cout << sol.minOperations(queries) << endl;

}