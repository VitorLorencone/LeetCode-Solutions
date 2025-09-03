/* 
Let n be the number of points in the vector

Time Complexity: O(n²)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sorting by x ascending and y descending
        sort(points.begin(), points.end(), [](auto &a, auto &b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
    
        int ans{0};
        for(int i = 0; i < points.size(); i++){
            int border{-1000000001};
            for(int j = i+1; j < points.size(); j++){
                if(points[i][1] >= points[j][1] && points[j][1] > border){
                    ans++;
                    border = points[j][1];
                    if(border == points[i][1]) break;
                }
            }
        }
        return ans;
    }
};

int main(){

    Solution sol = Solution();
    vector<vector<int>> pts = {{6,2},{4,4},{2,6}};

    cout << sol.numberOfPairs(pts) << endl; // 2

}