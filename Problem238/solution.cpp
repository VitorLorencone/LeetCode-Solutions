/* 
Let n be the size of the list nums

Time Complexity: O(n)
Space Complexity: O(n) -> Including the vector "ans";

Simple solution with two for loops calculating left and right multiplications

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int val = 1;
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            ans[i] = val;
            val *= nums[i];
        }
        
        val = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            ans[i] *= val;
            val *= nums[i];
        }

        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> p = {1, 2, 3, 4, 5};
    vector<int> answer = sol.productExceptSelf(p);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

}