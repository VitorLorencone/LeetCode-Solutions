/* 

Time Complexity: O(nlog(n))
Space Complexity: O(1)

Algorithm with cpp std::sort() in O(n*log(n)) and greedy algorithm in O(n). In this version, the sum
is calculated before the greedy loop, so it is faster than the .py code.

*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    long long largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        unsigned long int s = 0;

        for(int j = 0; j < nums.size(); j++){
            s += nums[j];
        }
        for(int i = nums.size()-1; i >= 2; i--){
            s -= nums[i];
            if(s > nums[i]){
                return s+nums[i];
            }
        }
        return -1;
    }
};

int main(){

    Solution sol = Solution();
    std::vector<int> prob = {1,12,1,2,5,50,3};
    std::cout << sol.largestPerimeter(prob) << std::endl; // returns 12

}