/* 
Let n be the size of *nums*

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int n = nums.size(), product = 1, cnt {};
        int l = 0, r = 0;
        while(r < n)
        {
            product *= nums[r++];
            while(l < r && product >= k)
                product /= nums[l++];
            
            cnt += (r - l);
        }
        return cnt;
    }
};

int main(){
    Solution sol = Solution();
    std::vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    std::cout << sol.numSubarrayProductLessThanK(nums, k);
}