/* 
Let n be the number of nodes in the tree

Time Complexity: O(n)
Space Complexity: O(n)

Solution with a recursive dfs.

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
    int res = 0;

    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        res = max(res, left+right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main(){

    Solution sol = Solution();
    TreeNode* p = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

    cout << sol.diameterOfBinaryTree(p) << endl;

    delete p->right;
    delete p->left;
    delete p;

}