/* 
n is the size of 's', m is the average word length and k is the broken letters length
Time Complexity: O(n * (m + k))
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> split(string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words = split(text, " ");
        int ans = 0;

        for(auto word : words){
            for(auto letter : word){
                if(word.find(letter, 0) != string::npos && brokenLetters.find(letter, 0) != string::npos){
                    ans += 1;
                    break;
                }
            }
        }

        return words.size() - ans;
    }
};

int main(){

    Solution sol = Solution();
    string x = "Leet Code";
    string y = "ed";

    cout << sol.canBeTypedWords(x, y) << endl;

}