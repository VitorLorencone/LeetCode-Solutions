/* 
Let n be the size of the list *points*

Time Complexity: O(n*log(n))
Space Complexity: O(1)

Simple solution with pre-processing sort and greedy algorithm.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int arrows = 0;
        vector<int> lastPoint = {-1, -1};
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] >= lastPoint[0] && points[i][0] <= lastPoint[1]){
                lastPoint[1] = min(lastPoint[1], points[i][1]);
                continue;
            }
            arrows++;
            lastPoint = points[i];
        }
        return arrows;
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<int>> p = {{1,2},{2,3},{3,4},{4,5}};
    cout << sol.findMinArrowShots(p);
}