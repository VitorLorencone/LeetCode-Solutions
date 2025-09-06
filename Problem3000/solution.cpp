/* 
Time Complexity: O(nlog(n))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal{0}; int maxArea{0};
        for(int i = 0; i < dimensions.size(); i++){
            int h = dimensions[i][0]; int w = dimensions[i][1]; int diagonal = h*h+w*w;
            if(diagonal > maxDiagonal){
                maxDiagonal = diagonal;
                maxArea = h*w;
            } else if(diagonal == maxDiagonal) maxArea = max(maxArea, h*w);
        }
        return maxArea;
    }
};

int main(){

    Solution sol = Solution();
    vector<vector<int>> dimensions = {{9,3},{8,6}};

    cout << sol.areaOfMaxDiagonal(dimensions) << endl;

}