/* 
Let n be the number of nodes in the tree and h be the height of the tree

Time Complexity: O(n)
Space Complexity: O(h)

A recursive solution using dfs.

*/

#include <iostream>
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
    void dfs(TreeNode* node, int level = 0){
        if(node == nullptr){return;}  
        if(level > currentLevel){
            currentLevel = level;
            value = node->val;
        }
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        value = root->val;
        dfs(root);
        return value;
    }
private:
    int value = 0;
    int currentLevel = 0;
};

int main(){

    Solution sol = Solution();
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)));

    cout << sol.findBottomLeftValue(root) << endl;

    delete root->right;
    delete root->left;
    delete root;

}