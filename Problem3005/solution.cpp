/* 
Let n be the size of the list nums

Time Complexity: O(n)
Space Complexity: O(n)

A solution using hash map for counting.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        int ans = 0;
        std::unordered_map<int, int> dict;

        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]] += 1;
        }

        for(const auto& pair : dict){
            if(pair.second > maxFreq){
                maxFreq = pair.second;
                ans = pair.second;
            }else if(pair.second == maxFreq){
                ans += pair.second;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> p = {1, 2, 3, 4, 5};
    cout << sol.maxFrequencyElements(p) << endl;
}