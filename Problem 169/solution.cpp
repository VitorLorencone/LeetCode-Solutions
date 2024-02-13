/* 

Time Complexity: O(n)
Memory Complexity: O(1)

Something interesting is that this algorithm has a specific name and creators, it's called 
the Boyer Moore majority voting algorithm and it's amazing for achieving this result of time 
and memory complexity. Its operation is quite simple, yet ingenious.

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0, m = 0;

        for(int i = 0; i < nums.size(); i++){
            if(c == 0){
                m = nums[i];
                c = 1;
            }else if(m == nums[i]){
                c++;
            }else{
                c--;
            }
        }
        return m;
    }
};

int main(){

    Solution sol = Solution();
    vector<int> prob = {2,2,1,1,1,2,2};

    cout << sol.majorityElement(prob) << endl; // returns 2

}