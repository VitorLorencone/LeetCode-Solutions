/* 
Let n be the size of *nums*

Time Complexity: O(n)
Space Complexity: O(1)

Two pointer solution.

*/

#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main(){
    Solution sol = Solution();
    std::vector<int> nums = {1,2,6,5,4,3,2};
    std::cout << sol.findDuplicate(nums);
}