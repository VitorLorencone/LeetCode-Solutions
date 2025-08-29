/* 
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int p = 0;
        int q = nums.size()-1;
        vector<int> ans(nums.size());
        int i = nums.size()-1;
        while(p != q){
            if(abs(nums[p]) > abs(nums[q])){
                ans[i] = nums[p]*nums[p];
                p++;
            }else{
                ans[i] = nums[q]*nums[q];
                q--;
            }
            i--;
        }
        ans[0] = nums[p]*nums[p];
        return ans;
    }
};