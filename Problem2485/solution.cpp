/* 

Time Complexity: O(n)
Space Complexity: O(1)

A very simple solution calculating the max sum and the subtracting each value in nums
this way, the remaining number at the end of the for loop is our answer.

*/

#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int total = (n*(n+1))/2;
        for(int i = 0; i < n; i++){
            total -= nums[i];
        }
        return total;
    }
};

int main(){

    Solution sol = Solution();
    std::vector<int> prob = {9,6,4,2,3,5,7,0,1};

    std::cout << sol.missingNumber(prob) << std::endl;

}