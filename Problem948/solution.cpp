/* 
Let n be tokens.size()

Time Complexity: O(nlog(n))
Space Complexity: O(1)

A solution using greedy, two pointers and sort.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        int pts = 0;
        int maxPts = 0;
        int p = 0;
        int q = tokens.size() - 1;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[p] <= power){
                power -= tokens[p];
                p++;
                pts++;
                maxPts = max(maxPts, pts);
                continue;
            }else if(pts > 0){
                power += tokens[q];
                q -= 1;
                pts -= 1;
                continue;
            }
            break;
        }
        return maxPts;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> tks = {100,200,300,400};
    int pwr = 200;
    cout << sol.bagOfTokensScore(tks, pwr) << endl;
}