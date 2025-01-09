/* 
Let `n` be the length of `words`
Let `m` be the length of `pref`

Time Complexity: O(n*m)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrefix(const string& txt, const string& pat) {
        if(pat.empty()) return true;
        if(txt.length() < pat.length()) return false;

        int i = 0;
        int j = 0;

        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == pat.length()){
                    return true;
                }
            }else{
                return false;
            }
        }
        return false;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            if(isPrefix(words[i], pref)){
                ans++;
            }
        }
        return ans;
    }
};


int main(){

    Solution sol = Solution();
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";

    cout << sol.prefixCount(words, pref) << endl;

}