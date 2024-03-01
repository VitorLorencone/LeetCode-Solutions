/* 
Let n be the number of nodes in the tree and h be the height of the tree

Time Complexity: O(n)
Space Complexity: O(n) -> values vector use O(h) but the worst case in call stack is O(n)

A recursive solution using dfs.
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solver(TreeNode* node, int level = 0){
        int sign = -2*(level%2)+1;
        if(node == nullptr || solution == false){return;}
        if(node->val%2 == level%2){
            solution = false;
            return;
        }
        if(values.size() <= level){values.push_back(node->val);}
        else if(values[level]*sign < node->val*sign){values[level] = node->val;}
        else{solution = false;}
        solver(node->left, level+1);
        solver(node->right, level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        solver(root);
        return solution;
    }
private:
    bool solution = true;
    std::vector<int> values = {};
};

int main(){

    Solution sol = Solution();
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(3), new TreeNode(5)), new TreeNode(2, new TreeNode(7), nullptr));

    cout << sol.isEvenOddTree(root) << endl;

    delete root->right;
    delete root->left;
    delete root;

}