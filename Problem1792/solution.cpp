/* 
Time Complexity: O(nlogn + extraStudents * logn)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        auto profit = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++){
            pq.push({profit(classes[i][0], classes[i][1]), i});
        }

        while(extraStudents--){
            auto [gain, idx] = pq.top();
            pq.pop();
            classes[idx][0]++; classes[idx][1]++;
            pq.push({profit(classes[idx][0], classes[idx][1]), idx});
        }

        double sum = 0;
        for(auto cl : classes) sum += (double)cl[0]/cl[1];

        return sum/n;
    }
};

int main(){

    Solution sol = Solution();
    vector<vector<int>> classes = {{1,2}, {3,5}, {2,2}};
    int extraStudents = 2;

    cout << sol.maxAverageRatio(classes, extraStudents) << endl;

}