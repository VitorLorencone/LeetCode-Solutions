/* 

Time Complexity: O(log(n))
Space Complexity: O(1)

A very simple solution using binary search.

*/

#include <iostream>

class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n;
        while (left <= right){
            int middle = (left+right) / 2;
            int sumLeft = (middle+1)*middle/2;
            int sumRight = (middle+n)*(n-middle+1)/2;
            if(sumLeft == sumRight){return middle;}
            else if(sumLeft < sumRight){left = middle+1;}
            else{right = middle-1;}
        }
        return -1;
    }
};

int main(){

    Solution sol = Solution();
    int n = 8;

    std::cout << sol.pivotInteger(8) << std::endl;

}